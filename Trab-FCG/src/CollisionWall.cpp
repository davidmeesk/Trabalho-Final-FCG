#include "CollisionWall.h"

void CollisionWall::setFrontFace(glm::vec4 faceInput[2]){
    frontFace[0]=faceInput[0];
    frontFace[1]=faceInput[1];

}

void CollisionWall::setBackFace(glm::vec4 faceInput[2]){
    backFace[0]=faceInput[0];
    backFace[1]=faceInput[1];
}


void CollisionWall::setFrontLeft(glm::vec4 pointInput){
    frontFace[0]=pointInput;
}
void CollisionWall::setFrontRight(glm::vec4 pointInput){
    frontFace[1]=pointInput;
}

void CollisionWall::setBackLeft(glm::vec4 pointInput){
    backFace[0]=pointInput;
}
void CollisionWall::setBackRight(glm::vec4 pointInput){
    backFace[1]=pointInput;
}

glm::vec4 CollisionWall::getFrontLeft(){
    return frontFace[0];
}
glm::vec4 CollisionWall::getFrontRight(){
    return frontFace[1];
}

glm::vec4 CollisionWall::getBackLeft(){
    return backFace[0];
}
glm::vec4 CollisionWall::getBackRight(){
    return backFace[1];
}

CollisionWall::CollisionWall(glm::vec4 frontFaceInput[2],glm::vec4 backFaceInput[2])
{
    setFrontFace(frontFaceInput);
    setBackFace(backFaceInput);
}

CollisionWall::~CollisionWall()
{
    //dtor
}



bool CollisionWall::isInWall(glm::vec4 points[4]){
    glm::vec3 rectangle[4];
    rectangle[0]= glm::vec3(getFrontLeft().x,getFrontLeft().z,1);
    rectangle[1]= glm::vec3(getFrontRight().x,getFrontRight().z,1);
    rectangle[2]= glm::vec3(getBackLeft().x,getBackLeft().z,1);
    rectangle[3]= glm::vec3(getBackRight().x,getBackRight().z,1);

    glm::vec3 objectPoints3[4];
    objectPoints3[0]= glm::vec3(points[0].x,points[0].z,1);
    objectPoints3[1]= glm::vec3(points[1].x,points[1].z,1);
    objectPoints3[2]= glm::vec3(points[2].x,points[2].z,1);
    objectPoints3[3]= glm::vec3(points[3].x,points[3].z,1);

    for (int i=0;i<4;i++){
        float f01=edgeEquation(rectangle[0],rectangle[1],objectPoints3[i]);
        float f13=edgeEquation(rectangle[1],rectangle[3],objectPoints3[i]);
        float f32=edgeEquation(rectangle[3],rectangle[2],objectPoints3[i]);
        float f20=edgeEquation(rectangle[2],rectangle[0],objectPoints3[i]);
        if((f01>=0 && f13>=0)&&(f32>=0&&f20>=0))
            return true;

    }
    return false;


}

float CollisionWall::edgeEquation(glm::vec3 pontoA,glm::vec3 pontoB,glm::vec3 toTest){
    glm::vec3 v=pontoB-pontoA;
    glm::vec3 vLine=glm::vec3(v.y,-1*v.x,0);
    return glm::dot(vLine,(toTest-pontoA));


}

