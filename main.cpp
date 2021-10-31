#include <iostream>

#include <random>
#include <chrono>
#include <memory>
#include <deque>

#include <benchmark/benchmark.h>

#include "ComponentsToBenchmark.h"

static std::string BM_EmptyEntityManagerCreation_Name = "Create empty entity manager";
static void BM_EmptyEntityManagerCreation(benchmark::State& state) {
	for (auto _ : state)
	{
		ComponentFactory componentFactory;
		EntityGenerator entityGenerator;
		EntityManager entityManager(componentFactory, entityGenerator);
	}
}

static std::string BM_EmptyEntityAddition_Name = "Add one entity without components";
static void BM_EmptyEntityAddition(benchmark::State& state) {
	ComponentFactory componentFactory;
	EntityGenerator entityGenerator;
	EntityManager entityManager(componentFactory, entityGenerator);

	for (auto _ : state)
	{
		entityManager.addEntity();
	}
}

static std::string BM_CreateEntityWithOneComponent_Name = "Add one entity with one component";
static void BM_CreateEntityWithOneComponent(benchmark::State& state) {
	ComponentFactory componentFactory;
	RegisterNumberedComponents(componentFactory);
	EntityGenerator entityGenerator;
	EntityManager entityManager(componentFactory, entityGenerator);

	for (auto _ : state)
	{
		Entity entity = entityManager.addEntity();
		entityManager.addComponent<ComponentOne>(entity);
	}
}

static std::string BM_CreateEntityWithOneComponentWithOneNonMatchingIndex_Name = "Add one entity with one component while having one index (the component not in the index)";
static void BM_CreateEntityWithOneComponentWithOneNonMatchingIndex(benchmark::State& state) {
	ComponentFactory componentFactory;
	RegisterNumberedComponents(componentFactory);
	EntityGenerator entityGenerator;
	EntityManager entityManager(componentFactory, entityGenerator);

	entityManager.initIndex<ComponentTwo>();

	for (auto _ : state)
	{
		Entity entity = entityManager.addEntity();
		entityManager.addComponent<ComponentOne>(entity);
	}
}

static std::string BM_CreateEntityWithOneComponentInOneIndex_Name = "Add one entity with one component while having one index (the component in the index)";
static void BM_CreateEntityWithOneComponentInOneIndex(benchmark::State& state) {
	ComponentFactory componentFactory;
	RegisterNumberedComponents(componentFactory);
	EntityGenerator entityGenerator;
	EntityManager entityManager(componentFactory, entityGenerator);

	entityManager.initIndex<ComponentOne>();

	for (auto _ : state)
	{
		Entity entity = entityManager.addEntity();
		entityManager.addComponent<ComponentOne>(entity);
	}
}

static std::string BM_CreateEntityWithSixteenComponents_Name = "Add one entity with 16 components";
static void BM_CreateEntityWithSixteenComponents(benchmark::State& state) {
	ComponentFactory componentFactory;
	RegisterNumberedComponents(componentFactory);
	EntityGenerator entityGenerator;
	EntityManager entityManager(componentFactory, entityGenerator);

	for (auto _ : state)
	{
		Entity entity = entityManager.addEntity();
		entityManager.addComponent<ComponentOne>(entity);
		entityManager.addComponent<ComponentTwo>(entity);
		entityManager.addComponent<ComponentThree>(entity);
		entityManager.addComponent<ComponentFour>(entity);
		entityManager.addComponent<ComponentFive>(entity);
		entityManager.addComponent<ComponentSix>(entity);
		entityManager.addComponent<ComponentSeven>(entity);
		entityManager.addComponent<ComponentEight>(entity);
		entityManager.addComponent<ComponentNine>(entity);
		entityManager.addComponent<ComponentTen>(entity);
		entityManager.addComponent<ComponentEleven>(entity);
		entityManager.addComponent<ComponentTwelve>(entity);
		entityManager.addComponent<ComponentThirteen>(entity);
		entityManager.addComponent<ComponentFourteen>(entity);
		entityManager.addComponent<ComponentFifteen>(entity);
		entityManager.addComponent<ComponentSixteen>(entity);
	}
}

static std::string BM_CreateEntityWithSixteenComponentsWithEightNonMatchingIndexes_Name = "Add one entity with 16 components while having 8 indexes (the components not in the indexes)";
static void BM_CreateEntityWithSixteenComponentsWithEightNonMatchingIndexes(benchmark::State& state) {
	ComponentFactory componentFactory;
	RegisterNumberedComponents(componentFactory);
	EntityGenerator entityGenerator;
	EntityManager entityManager(componentFactory, entityGenerator);

	entityManager.initIndex<TransformComponent, ComponentOne, ComponentTwo, ComponentThree, ComponentFour,
		ComponentFive, ComponentSix, ComponentSeven, ComponentEight, ComponentNine, ComponentTen, ComponentEleven,
		ComponentTwelve, ComponentThirteen, ComponentFourteen, ComponentFifteen, ComponentSixteen>();

	entityManager.initIndex<TransformComponent, ComponentTwo, ComponentFour, ComponentSix, ComponentEight, ComponentTen,
		ComponentTwelve, ComponentFourteen, ComponentSixteen>();

	entityManager.initIndex<TransformComponent, ComponentThree, ComponentSix, ComponentNine, ComponentTwelve,
		ComponentFifteen>();

	entityManager.initIndex<TransformComponent, ComponentOne, ComponentFive, ComponentNine, ComponentThirteen>();

	entityManager.initIndex<TransformComponent, ComponentOne, ComponentTwo, ComponentThree, ComponentFour,
		ComponentFive, ComponentSix, ComponentSeven, ComponentEight>();

	entityManager.initIndex<TransformComponent, ComponentNine, ComponentTen, ComponentEleven, ComponentTwelve,
		ComponentThirteen, ComponentFourteen, ComponentFifteen, ComponentSixteen>();

	entityManager.initIndex<TransformComponent, ComponentOne, ComponentThree, ComponentFive>();

	entityManager.initIndex<TransformComponent, ComponentTwo, ComponentFour,ComponentSix>();

	for (auto _ : state)
	{
		Entity entity = entityManager.addEntity();
		entityManager.addComponent<ComponentOne>(entity);
		entityManager.addComponent<ComponentTwo>(entity);
		entityManager.addComponent<ComponentThree>(entity);
		entityManager.addComponent<ComponentFour>(entity);
		entityManager.addComponent<ComponentFive>(entity);
		entityManager.addComponent<ComponentSix>(entity);
		entityManager.addComponent<ComponentSeven>(entity);
		entityManager.addComponent<ComponentEight>(entity);
		entityManager.addComponent<ComponentNine>(entity);
		entityManager.addComponent<ComponentTen>(entity);
		entityManager.addComponent<ComponentEleven>(entity);
		entityManager.addComponent<ComponentTwelve>(entity);
		entityManager.addComponent<ComponentThirteen>(entity);
		entityManager.addComponent<ComponentFourteen>(entity);
		entityManager.addComponent<ComponentFifteen>(entity);
		entityManager.addComponent<ComponentSixteen>(entity);
	}
}

static std::string BM_CreateEntityWithSixteenComponentsInOneSmallIndex_Name = "Add one entity with 16 components while having 1 small index (the components in the index)";
static void BM_CreateEntityWithSixteenComponentsInOneSmallIndex(benchmark::State& state) {
	ComponentFactory componentFactory;
	RegisterNumberedComponents(componentFactory);
	EntityGenerator entityGenerator;
	EntityManager entityManager(componentFactory, entityGenerator);

	entityManager.initIndex<ComponentNine>();

	for (auto _ : state)
	{
		Entity entity = entityManager.addEntity();
		entityManager.addComponent<ComponentOne>(entity);
		entityManager.addComponent<ComponentTwo>(entity);
		entityManager.addComponent<ComponentThree>(entity);
		entityManager.addComponent<ComponentFour>(entity);
		entityManager.addComponent<ComponentFive>(entity);
		entityManager.addComponent<ComponentSix>(entity);
		entityManager.addComponent<ComponentSeven>(entity);
		entityManager.addComponent<ComponentEight>(entity);
		entityManager.addComponent<ComponentNine>(entity);
		entityManager.addComponent<ComponentTen>(entity);
		entityManager.addComponent<ComponentEleven>(entity);
		entityManager.addComponent<ComponentTwelve>(entity);
		entityManager.addComponent<ComponentThirteen>(entity);
		entityManager.addComponent<ComponentFourteen>(entity);
		entityManager.addComponent<ComponentFifteen>(entity);
		entityManager.addComponent<ComponentSixteen>(entity);
	}
}

static std::string BM_CreateEntityWithSixteenComponentsInOneBigIndex_Name = "Add one entity with 16 components while having 1 big index (the components in the index)";
static void BM_CreateEntityWithSixteenComponentsInOneBigIndex(benchmark::State& state) {
	ComponentFactory componentFactory;
	RegisterNumberedComponents(componentFactory);
	EntityGenerator entityGenerator;
	EntityManager entityManager(componentFactory, entityGenerator);

	entityManager.initIndex<ComponentOne, ComponentTwo, ComponentThree, ComponentFour, ComponentFive,
		ComponentSix, ComponentSeven, ComponentEight, ComponentNine, ComponentTen, ComponentEleven,
		ComponentTwelve, ComponentThirteen, ComponentFourteen, ComponentFifteen, ComponentSixteen>();

	for (auto _ : state)
	{
		Entity entity = entityManager.addEntity();
		entityManager.addComponent<ComponentOne>(entity);
		entityManager.addComponent<ComponentTwo>(entity);
		entityManager.addComponent<ComponentThree>(entity);
		entityManager.addComponent<ComponentFour>(entity);
		entityManager.addComponent<ComponentFive>(entity);
		entityManager.addComponent<ComponentSix>(entity);
		entityManager.addComponent<ComponentSeven>(entity);
		entityManager.addComponent<ComponentEight>(entity);
		entityManager.addComponent<ComponentNine>(entity);
		entityManager.addComponent<ComponentTen>(entity);
		entityManager.addComponent<ComponentEleven>(entity);
		entityManager.addComponent<ComponentTwelve>(entity);
		entityManager.addComponent<ComponentThirteen>(entity);
		entityManager.addComponent<ComponentFourteen>(entity);
		entityManager.addComponent<ComponentFifteen>(entity);
		entityManager.addComponent<ComponentSixteen>(entity);
	}
}

static std::string BM_CreateEntityWithSixteenComponentsInEightDifferentIndexes_Name = "Add one entity with 16 components while having 8 different index (the components are in the indexes)";
static void BM_CreateEntityWithSixteenComponentsInEightDifferentIndexes(benchmark::State& state) {
	ComponentFactory componentFactory;
	RegisterNumberedComponents(componentFactory);
	EntityGenerator entityGenerator;
	EntityManager entityManager(componentFactory, entityGenerator);

	// include all components
	entityManager.initIndex<ComponentOne, ComponentTwo, ComponentThree, ComponentFour, ComponentFive,
		ComponentSix, ComponentSeven, ComponentEight, ComponentNine, ComponentTen, ComponentEleven,
		ComponentTwelve, ComponentThirteen, ComponentFourteen, ComponentFifteen, ComponentSixteen>();

	// include only even components
	entityManager.initIndex<ComponentTwo, ComponentFour, ComponentSix, ComponentEight, ComponentTen,
		ComponentTwelve, ComponentFourteen, ComponentSixteen>();

	// include every third component
	entityManager.initIndex<ComponentThree, ComponentSix, ComponentNine, ComponentTwelve, ComponentFifteen>();

	// include every fourth component
	entityManager.initIndex<ComponentOne, ComponentFive, ComponentNine, ComponentThirteen>();

	// include first half of components
	entityManager.initIndex<ComponentOne, ComponentTwo, ComponentThree, ComponentFour, ComponentFive,
		ComponentSix, ComponentSeven, ComponentEight>();

	// include second half of components
	entityManager.initIndex<ComponentNine, ComponentTen, ComponentEleven, ComponentTwelve, ComponentThirteen,
		ComponentFourteen, ComponentFifteen, ComponentSixteen>();

	// include components 1 3 5
	entityManager.initIndex<ComponentOne, ComponentThree, ComponentFive>();

	// include components 2 4 5
	entityManager.initIndex<ComponentTwo, ComponentFour,ComponentSix>();

	for (auto _ : state)
	{
		Entity entity = entityManager.addEntity();
		entityManager.addComponent<ComponentOne>(entity);
		entityManager.addComponent<ComponentTwo>(entity);
		entityManager.addComponent<ComponentThree>(entity);
		entityManager.addComponent<ComponentFour>(entity);
		entityManager.addComponent<ComponentFive>(entity);
		entityManager.addComponent<ComponentSix>(entity);
		entityManager.addComponent<ComponentSeven>(entity);
		entityManager.addComponent<ComponentEight>(entity);
		entityManager.addComponent<ComponentNine>(entity);
		entityManager.addComponent<ComponentTen>(entity);
		entityManager.addComponent<ComponentEleven>(entity);
		entityManager.addComponent<ComponentTwelve>(entity);
		entityManager.addComponent<ComponentThirteen>(entity);
		entityManager.addComponent<ComponentFourteen>(entity);
		entityManager.addComponent<ComponentFifteen>(entity);
		entityManager.addComponent<ComponentSixteen>(entity);
	}
}

static void PrepareEntityManagerWithEntitesWithTwoRandomlyDistributedComponents(
	EntityManager& entityManager,
	std::mt19937& rng,
	size_t entityCount
	)
{
	for (size_t i = 0; i < entityCount; ++i)
	{
		Entity entity = entityManager.addEntity();
		if (rng() % 2 == 0)
		{
			TransformComponent* transform = entityManager.addComponent<TransformComponent>(entity);
			transform->x = 100.0f * rng() / rng.max();
			transform->y = 100.0f * rng() / rng.max();
		}

		if (rng() % 2 == 0)
		{
			MovementComponent* movement = entityManager.addComponent<MovementComponent>(entity);
			movement->speedPerTickX = 1.0f - 2.0f * rng() / rng.max();
			movement->speedPerTickY = 1.0f - 2.0f * rng() / rng.max();
		}
	}
}

static void BenchmarkIterationsOverPairs(benchmark::State& state, size_t entitiesCount)
{
	ComponentFactory componentFactory;
	componentFactory.registerComponent<TransformComponent>();
	componentFactory.registerComponent<MovementComponent>();
	EntityGenerator entityGenerator;
	EntityManager entityManager(componentFactory, entityGenerator);
	std::mt19937 rng(42);

	PrepareEntityManagerWithEntitesWithTwoRandomlyDistributedComponents(entityManager, rng, entitiesCount);
	entityManager.initIndex<MovementComponent, TransformComponent>();

	for (auto _ : state)
	{
		entityManager.forEachComponentSet<MovementComponent, TransformComponent>([](MovementComponent* movement, TransformComponent* transform)
		{
			transform->x += movement->speedPerTickX;
			transform->y += movement->speedPerTickY;
		});
	}
}

static std::string BM_IterateOverAbout1000PairsOfComponentsFrom4000Entities_Name = "Iterate over matching pairs of components (around 1000) from 4000 entities";
static void BM_IterateOverAbout1000PairsOfComponentsFrom4000Entities(benchmark::State& state) {
	BenchmarkIterationsOverPairs(state, 4000);
}

static std::string BM_IterateOver8000Entities_Name = "Iterate over matching pairs of components (around 2000) from 8000 entities";
static void BM_IterateOver8000Entities(benchmark::State& state) {
	BenchmarkIterationsOverPairs(state, 8000);
}

static std::string BM_IterateOver16000Entities_Name = "Iterate over matching pairs of components (around 4000) from 16000 entities";
static void BM_IterateOver16000Entities(benchmark::State& state) {
	BenchmarkIterationsOverPairs(state, 16000);
}

static std::string BM_IterateOver32000Entities_Name = "Iterate over matching pairs of components (around 8000) from 32000 entities";
static void BM_IterateOver32000Entities(benchmark::State& state) {
	BenchmarkIterationsOverPairs(state, 32000);
}

static std::string BM_IterateOver64000Entities_Name = "Iterate over matching pairs of components (around 16000) from 64000 entities";
static void BM_IterateOver64000Entities(benchmark::State& state) {
	BenchmarkIterationsOverPairs(state, 64000);
}

static std::string BM_IterateOver128000Entities_Name = "Iterate over matching pairs of components (around 32000) from 128000 entities";
static void BM_IterateOver128000Entities(benchmark::State& state) {
	BenchmarkIterationsOverPairs(state, 128000);
}

static std::string BM_IterateOver256000Entities_Name = "Iterate over matching pairs of components (around 64000) from 256000 entities";
static void BM_IterateOver256000Entities(benchmark::State& state) {
	BenchmarkIterationsOverPairs(state, 256000);
}

static std::string BM_IterateOver512000Entities_Name = "Iterate over matching pairs of components (around 128000) from 512000 entities";
static void BM_IterateOver512000Entities(benchmark::State& state) {
	BenchmarkIterationsOverPairs(state, 512000);
}

static std::string BM_IterateOverAbout1000PairsOfComponentsFrom4000EntitiesFrom16EntityManagers_Name = "Iterate over matching pairs of components (around 1000 per entity manager) from 16 entity managers having 4000 entities each";
static void BM_IterateOverAbout1000PairsOfComponentsFrom4000EntitiesFrom16EntityManagers(benchmark::State& state) {
	ComponentFactory componentFactory;
	componentFactory.registerComponent<TransformComponent>();
	componentFactory.registerComponent<MovementComponent>();
	EntityGenerator entityGenerator;
	std::mt19937 rng(42);

	std::deque<EntityManager> entityManagers;
	for (size_t i = 0; i < 16; ++i)
	{
		entityManagers.emplace_back(componentFactory, entityGenerator);
		PrepareEntityManagerWithEntitesWithTwoRandomlyDistributedComponents(entityManagers.back(), rng, 4000);
	}

	auto processor = [](MovementComponent* movement, TransformComponent* transform)
	{
		transform->x += movement->speedPerTickX;
		transform->y += movement->speedPerTickY;
	};

	for (auto _ : state)
	{
		for (auto& entityManager : entityManagers)
		{
			entityManager.forEachComponentSet<MovementComponent, TransformComponent>(processor);
		}
	}
}

static std::string BM_SelectAbout1000PairsOfComponentsFrom4000Entities_Name = "Select matching pairs of components (around 1000) from 4000 entities";
static void BM_SelectAbout1000PairsOfComponentsFrom4000Entities(benchmark::State& state) {
	ComponentFactory componentFactory;
	componentFactory.registerComponent<TransformComponent>();
	componentFactory.registerComponent<MovementComponent>();
	EntityGenerator entityGenerator;
	EntityManager entityManager(componentFactory, entityGenerator);

	std::mt19937 rng(42);

	PrepareEntityManagerWithEntitesWithTwoRandomlyDistributedComponents(entityManager, rng, 4000);

	std::vector<std::tuple<MovementComponent*, TransformComponent*>> components;
	components.reserve(1100);

	for (auto _ : state)
	{
		components.clear();
		entityManager.getComponents<MovementComponent, TransformComponent>(components);
	}
}

static std::string BM_SelectByAbout1000PairsOfComponentsFrom4000EntitiesFrom16EntityManagers_Name = "Select matching pairs of components (around 1000 per entity manager) from 16 entity managers having 4000 entities each";
static void BM_SelectByAbout1000PairsOfComponentsFrom4000EntitiesFrom16EntityManagers(benchmark::State& state) {
	ComponentFactory componentFactory;
	componentFactory.registerComponent<TransformComponent>();
	componentFactory.registerComponent<MovementComponent>();
	EntityGenerator entityGenerator;
	std::mt19937 rng(42);

	std::deque<EntityManager> entityManagers;
	for (size_t i = 0; i < 16; ++i)
	{
		entityManagers.emplace_back(componentFactory, entityGenerator);
		PrepareEntityManagerWithEntitesWithTwoRandomlyDistributedComponents(entityManagers.back(), rng, 4000);
	}

	std::vector<std::tuple<MovementComponent*, TransformComponent*>> components;
	components.reserve(17600);
	for (auto _ : state)
	{
		components.clear();
		for (auto& entityManager : entityManagers)
		{
			entityManager.getComponents<MovementComponent, TransformComponent>(components);
		}
	}
}

static std::string BM_CreateAndTransferEmptyEntity_Name = "Create and transfer entity without components to another entity manager";
static void BM_CreateAndTransferEmptyEntity(benchmark::State& state) {
	ComponentFactory componentFactory;
	EntityGenerator entityGenerator;
	EntityManager entityManager1(componentFactory, entityGenerator);
	EntityManager entityManager2(componentFactory, entityGenerator);

	for (auto _ : state)
	{
		Entity entity = entityManager1.addEntity();
		entityManager1.transferEntityTo(entityManager2, entity);
	}
}

static std::string BM_CreateAndTransferEntityWithTwoComponents_Name = "Create and transfer entity with two components to another entity manager";
static void BM_CreateAndTransferEntityWithTwoComponents(benchmark::State& state) {
	ComponentFactory componentFactory;
	RegisterNumberedComponents(componentFactory);
	EntityGenerator entityGenerator;
	EntityManager entityManager1(componentFactory, entityGenerator);
	EntityManager entityManager2(componentFactory, entityGenerator);

	for (auto _ : state)
	{
		Entity entity = entityManager1.addEntity();
		entityManager1.addComponent<ComponentOne>(entity);
		entityManager1.addComponent<ComponentTwo>(entity);
		entityManager1.transferEntityTo(entityManager2, entity);
	}
}

static std::string BM_CreateAndTransferEntityWithTwoComponentsInOneIndex_Name = "Create and transfer entity with two components to another entity manager (both have one index with both components)";
static void BM_CreateAndTransferEntityWithTwoComponentsInOneIndex(benchmark::State& state) {
	ComponentFactory componentFactory;
	RegisterNumberedComponents(componentFactory);
	EntityGenerator entityGenerator;
	EntityManager entityManager1(componentFactory, entityGenerator);
	EntityManager entityManager2(componentFactory, entityGenerator);

	entityManager1.initIndex<ComponentOne, ComponentTwo>();
	entityManager2.initIndex<ComponentOne, ComponentTwo>();

	for (auto _ : state)
	{
		Entity entity = entityManager1.addEntity();
		entityManager1.addComponent<ComponentOne>(entity);
		entityManager1.addComponent<ComponentTwo>(entity);
		entityManager1.transferEntityTo(entityManager2, entity);
	}
}

BENCHMARK(BM_EmptyEntityManagerCreation)->Name(BM_EmptyEntityManagerCreation_Name);
BENCHMARK(BM_EmptyEntityAddition)->Name(BM_EmptyEntityAddition_Name);
BENCHMARK(BM_CreateEntityWithOneComponent)->Name(BM_CreateEntityWithOneComponent_Name);
BENCHMARK(BM_CreateEntityWithOneComponentWithOneNonMatchingIndex)->Name(BM_CreateEntityWithOneComponentWithOneNonMatchingIndex_Name);
BENCHMARK(BM_CreateEntityWithOneComponentInOneIndex)->Name(BM_CreateEntityWithOneComponentInOneIndex_Name);
BENCHMARK(BM_CreateEntityWithSixteenComponents)->Name(BM_CreateEntityWithSixteenComponents_Name);
BENCHMARK(BM_CreateEntityWithSixteenComponentsWithEightNonMatchingIndexes)->Name(BM_CreateEntityWithSixteenComponentsWithEightNonMatchingIndexes_Name);
BENCHMARK(BM_CreateEntityWithSixteenComponentsInOneSmallIndex)->Name(BM_CreateEntityWithSixteenComponentsInOneSmallIndex_Name);
BENCHMARK(BM_CreateEntityWithSixteenComponentsInOneBigIndex)->Name(BM_CreateEntityWithSixteenComponentsInOneBigIndex_Name);
BENCHMARK(BM_CreateEntityWithSixteenComponentsInEightDifferentIndexes)->Name(BM_CreateEntityWithSixteenComponentsInEightDifferentIndexes_Name);
BENCHMARK(BM_IterateOverAbout1000PairsOfComponentsFrom4000Entities)->Name(BM_IterateOverAbout1000PairsOfComponentsFrom4000Entities_Name);

BENCHMARK(BM_IterateOver8000Entities)->Name(BM_IterateOver8000Entities_Name);
BENCHMARK(BM_IterateOver16000Entities)->Name(BM_IterateOver16000Entities_Name);
BENCHMARK(BM_IterateOver32000Entities)->Name(BM_IterateOver32000Entities_Name);
BENCHMARK(BM_IterateOver64000Entities)->Name(BM_IterateOver64000Entities_Name);
BENCHMARK(BM_IterateOver128000Entities)->Name(BM_IterateOver128000Entities_Name);
BENCHMARK(BM_IterateOver256000Entities)->Name(BM_IterateOver256000Entities_Name);
BENCHMARK(BM_IterateOver512000Entities)->Name(BM_IterateOver512000Entities_Name);

BENCHMARK(BM_IterateOverAbout1000PairsOfComponentsFrom4000EntitiesFrom16EntityManagers)->Name(BM_IterateOverAbout1000PairsOfComponentsFrom4000EntitiesFrom16EntityManagers_Name);
BENCHMARK(BM_SelectAbout1000PairsOfComponentsFrom4000Entities)->Name(BM_SelectAbout1000PairsOfComponentsFrom4000Entities_Name);
BENCHMARK(BM_SelectByAbout1000PairsOfComponentsFrom4000EntitiesFrom16EntityManagers)->Name(BM_SelectByAbout1000PairsOfComponentsFrom4000EntitiesFrom16EntityManagers_Name);
BENCHMARK(BM_CreateAndTransferEmptyEntity)->Name(BM_CreateAndTransferEmptyEntity_Name);
BENCHMARK(BM_CreateAndTransferEntityWithTwoComponents)->Name(BM_CreateAndTransferEntityWithTwoComponents_Name);
BENCHMARK(BM_CreateAndTransferEntityWithTwoComponentsInOneIndex)->Name(BM_CreateAndTransferEntityWithTwoComponentsInOneIndex_Name);

BENCHMARK_MAIN();
