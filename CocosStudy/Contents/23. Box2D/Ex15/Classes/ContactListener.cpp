#include "ContactListener.h"

ContactListener::ContactListener(){}
ContactListener::~ContactListener() {}

void ContactListener::BeginContact(b2Contact* contact)
{
	log("Contact:Begin");
}

void ContactListener::EndContact(b2Contact* contact)
{
	log("Contact:End");
}

void ContactListener::PreSolve(b2Contact * contact, const b2Manifold * oldManifold)
{
	log("Contact:PreSolve");
}

void ContactListener::PostSolve(b2Contact * contact, const b2ContactImpulse * imPulse)
{
	log("Contact:PostSolve....1");

	b2Fixture* fix1 = contact->GetFixtureA();
	b2Fixture* fix2 = contact->GetFixtureB();

	b2Body *bodyA = fix1->GetBody();
	b2Body *bodyB = fix2->GetBody();

	if(bodyA->GetType() == b2_dynamicBody || bodyB->GetType() == b2_dynamicBody)
		log("Contact:imPulse...%f", imPulse->normalImpulses[0]);

}

