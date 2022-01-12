#pragma once

#include "entity_manager.h"

enum class ComponentType
{
	One = 0,
	Two,
	Three,
	Four,
	Five,
	Six,
	Seven,
	Eight,
	Nine,
	Ten,
	Eleven,
	Twelve,
	Thirteen,
	Fourteen,
	Fifteen,
	Sixteen,
	Transform,
	Movement
};

using EntityManager = RaccoonEcs::EntityManagerImpl<ComponentType>;
using ComponentFactory = RaccoonEcs::ComponentFactoryImpl<ComponentType>;
using EntityGenerator = RaccoonEcs::IncrementalEntityGenerator;
using Entity = RaccoonEcs::Entity;

struct TransformComponent
{
	float x;
	float y;

	static ComponentType GetTypeId() { return ComponentType::Transform; }
};

struct MovementComponent
{
	float speedPerTickX;
	float speedPerTickY;

	static ComponentType GetTypeId() { return ComponentType::Movement; }
};

template<int Index>
struct ComponentN
{
	float data[4];
	static ComponentType GetTypeId() { return static_cast<ComponentType>(Index); }
};

using ComponentOne = ComponentN<0>;
using ComponentTwo = ComponentN<1>;
using ComponentThree = ComponentN<2>;
using ComponentFour = ComponentN<3>;
using ComponentFive = ComponentN<4>;
using ComponentSix = ComponentN<5>;
using ComponentSeven = ComponentN<6>;
using ComponentEight = ComponentN<7>;
using ComponentNine = ComponentN<8>;
using ComponentTen = ComponentN<9>;
using ComponentEleven = ComponentN<10>;
using ComponentTwelve = ComponentN<11>;
using ComponentThirteen = ComponentN<12>;
using ComponentFourteen = ComponentN<13>;
using ComponentFifteen = ComponentN<14>;
using ComponentSixteen = ComponentN<15>;

inline void RegisterNumberedComponents(ComponentFactory & inOutFactory) {
	inOutFactory.registerComponent<ComponentOne>();
	inOutFactory.registerComponent<ComponentTwo>();
	inOutFactory.registerComponent<ComponentThree>();
	inOutFactory.registerComponent<ComponentFour>();
	inOutFactory.registerComponent<ComponentFive>();
	inOutFactory.registerComponent<ComponentSix>();
	inOutFactory.registerComponent<ComponentSeven>();
	inOutFactory.registerComponent<ComponentEight>();
	inOutFactory.registerComponent<ComponentNine>();
	inOutFactory.registerComponent<ComponentTen>();
	inOutFactory.registerComponent<ComponentEleven>();
	inOutFactory.registerComponent<ComponentTwelve>();
	inOutFactory.registerComponent<ComponentThirteen>();
	inOutFactory.registerComponent<ComponentFourteen>();
	inOutFactory.registerComponent<ComponentFifteen>();
	inOutFactory.registerComponent<ComponentSixteen>();
}
