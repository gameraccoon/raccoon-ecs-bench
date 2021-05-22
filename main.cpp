#include <iostream>

#include <random>
#include <chrono>

#include <benchmark/benchmark.h>

#include "ComponentsToBenchmark.h"

static void BM_EmptyEntityManagerCreation(benchmark::State& state) {
	for (auto _ : state)
	{
		ComponentFactory componentFactory;
		EntityGenerator entityGenerator;
		EntityManager entityManager(componentFactory, entityGenerator);
	}
}
BENCHMARK(BM_EmptyEntityManagerCreation);

static void BM_EmptyEntityAddition(benchmark::State& state) {
	ComponentFactory componentFactory;
	EntityGenerator entityGenerator;
	EntityManager entityManager(componentFactory, entityGenerator);

	for (auto _ : state)
	{
		entityManager.addEntity();
	}
}
BENCHMARK(BM_EmptyEntityAddition);

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
BENCHMARK(BM_CreateEntityWithOneComponent);

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
BENCHMARK(BM_CreateEntityWithOneComponentWithOneNonMatchingIndex);

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
BENCHMARK(BM_CreateEntityWithOneComponentInOneIndex);

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
BENCHMARK(BM_CreateEntityWithSixteenComponents);

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
BENCHMARK(BM_CreateEntityWithSixteenComponentsWithEightNonMatchingIndexes);

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
BENCHMARK(BM_CreateEntityWithSixteenComponentsInOneSmallIndex);

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
BENCHMARK(BM_CreateEntityWithSixteenComponentsInOneBigIndex);

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
BENCHMARK(BM_CreateEntityWithSixteenComponentsInEightDifferentIndexes);

static void BM_IterateOverAbout1000PairsOfComponentsFrom4000Entities(benchmark::State& state) {
	ComponentFactory componentFactory;
	componentFactory.registerComponent<TransformComponent>();
	componentFactory.registerComponent<MovementComponent>();
	EntityGenerator entityGenerator;
	EntityManager entityManager(componentFactory, entityGenerator);

	std::mt19937 rng(42);

	for (size_t i = 0; i < 4000; ++i)
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

	for (auto _ : state)
	{
		entityManager.forEachComponentSet<MovementComponent, TransformComponent>([](MovementComponent* movement, TransformComponent* transform)
		{
			transform->x += movement->speedPerTickX;
			transform->y += movement->speedPerTickY;
		});
	}
}
BENCHMARK(BM_IterateOverAbout1000PairsOfComponentsFrom4000Entities);

static void BM_SelectAbout1000PairsOfComponentsFrom4000Entities(benchmark::State& state) {
	ComponentFactory componentFactory;
	componentFactory.registerComponent<TransformComponent>();
	componentFactory.registerComponent<MovementComponent>();
	EntityGenerator entityGenerator;
	EntityManager entityManager(componentFactory, entityGenerator);

	std::mt19937 rng(42);

	for (size_t i = 0; i < 4000; ++i)
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

	std::vector<std::tuple<MovementComponent*, TransformComponent*>> components;
	components.reserve(1100);

	for (auto _ : state)
	{
		components.clear();
		entityManager.getComponents<MovementComponent, TransformComponent>(components);
	}
}
BENCHMARK(BM_SelectAbout1000PairsOfComponentsFrom4000Entities);

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
BENCHMARK(BM_CreateAndTransferEmptyEntity);

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
BENCHMARK(BM_CreateAndTransferEntityWithTwoComponents);


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
BENCHMARK(BM_CreateAndTransferEntityWithTwoComponentsInOneIndex);

BENCHMARK_MAIN();
