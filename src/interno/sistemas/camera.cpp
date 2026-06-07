#include "camera.hpp"
#include <raylib.h>
#include <vector>

using namespace std;

Camera2D MainCamera::Camera;

MainCamera::MainCamera(CameraTarget *target, Vector2 offset, float rotation, float zoom){
    Target = target;
    Camera = {offset, Target->GetTargetPosicao(), rotation, zoom};
}

void MainCamera::Update(){
    Camera.target = Target->GetTargetPosicao();
}