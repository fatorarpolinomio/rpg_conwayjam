#ifndef CAMERA_H
#define CAMERA_H

#include <raylib.h>
#include <vector>

using namespace std;

class CameraTarget{

    public:
        CameraTarget() = default;
        virtual ~CameraTarget() = default;
        virtual Vector2 GetTargetPosicao() = 0;
};

class MainCamera{
    private:
        static Camera2D Camera;
        CameraTarget *Target; 

    public:
        MainCamera(CameraTarget *target, Vector2 offset, float rotation, float zoom);
        void Update();
        
        void SetTarget(CameraTarget *newTarget){Target = newTarget;}
        void SetOffset(Vector2 newOffset){Camera.offset = newOffset;}
        void SetRotation(float newRotation){Camera.rotation = newRotation;}
        void SetZoom(float newZoom){Camera.zoom = newZoom;}

        Camera2D GetCamera(){return Camera;}


};

#endif