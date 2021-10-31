#!/usr/bin/python3

import json
import os
import shutil


def remove_old_results():
	bin_path = "./bin"
	if os.path.exists(bin_path) and os.path.isdir(bin_path):
		shutil.rmtree(bin_path)


def build_benchmark():
	os.makedirs("build", exist_ok=True)
	os.chdir('./build')
	os.system("cmake .. -DCMAKE_BUILD_TYPE:String=Release")
	os.chdir('..')
	os.system("cmake --build build")


def run_benchmark(executable_path, output_path, output_format):
	os.system("{exe_path} --benchmark_out_format={format} --benchmark_out={out_path}".format(
		exe_path = executable_path,
		format = output_format,
		out_path = output_path,
	))


def convert_gbench_json_result_to_markdown(json_path):
	md_description = ""
	
	with open(json_path) as results_data_file:
		results_data = json.load(results_data_file)

		context = results_data["context"]
		md_description += context["date"] + "  \n"
		md_description += "Run on ({num_cpus} X {mhz_per_cpu} MHz CPU s)  \n".format(**context)
		md_description += "CPU Caches:  \n"
		for cache in context["caches"]:
			cache["size_kb"] = cache["size"] / 1024
			cache["count"] = context["num_cpus"] / cache["num_sharing"]
			md_description += "&nbsp;&nbsp;&nbsp;&nbsp;L{level} {type} {size_kb} KiB (x{count:.0f})  \n".format(**cache)
		if context["library_build_type"] != "release":
			md_description += "Build type: {library_build_type}  \n".format(**context)
		md_description += "Load Average: {}\n\n".format(", ".join(map(str, context["load_avg"])))
		if context["cpu_scaling_enabled"]:
			md_description += "***WARNING*** CPU scaling is enabled, the benchmark real time measurements may be noisy and will incur extra overhead.\n\n"

		md_description += "Benchmark | Time | CPU | Iterations\n--- | --- | --- | ---\n"
		for benchmark in results_data["benchmarks"]:
			md_description += "{name} | {real_time:.0f} ns | {cpu_time:.0f} ns | {iterations}\n".format(**benchmark)

	return md_description


def write_str_to_file(file_path, str):
	with open(file_path, "w") as file:
		file.write(str)


remove_old_results()
build_benchmark()
run_benchmark("./bin/RaccoonEcsBenchmark", "bin/output.json", "json")
markdown = convert_gbench_json_result_to_markdown("bin/output.json")
write_str_to_file("README.md", markdown)
