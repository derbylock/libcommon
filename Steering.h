#ifndef COMMON_STEERING_H
#define COMMON_STEERING_H

#include "Vector3.h"
#include "Vehicle.h"

namespace Common {

class Steering {
	public:
		Steering(const Vehicle& e);
		Vector3 seek(const Vector3& tgtpos);
		Vector3 flee(const Vector3& threatpos);
		Vector3 arrive(const Vector3& tgtpos);
		Vector3 pursuit(const Vehicle& tgt);
		Vector3 evade(const Vehicle& threat);
		Vector3 wander(float radius = 2.0f, float distance = 1.0f, float jitter = 3.0f);
		Vector3 obstacleAvoidance(const std::vector<Obstacle*> obstacles);
		Vector3 wallAvoidance(const std::vector<Wall*> walls);
		Vector3 cohesion(const std::vector<Entity*> neighbours);
		Vector3 separation(const std::vector<Entity*> neighbours);
		Vector3 offsetPursuit(const Vehicle& leader, const Vector3& offset);
		bool accumulate(Vector3& runningTotal, const Vector3& add);

	private:
		const Vehicle& mUnit;
		Vector3 mWanderTarget;
};

}

#endif

