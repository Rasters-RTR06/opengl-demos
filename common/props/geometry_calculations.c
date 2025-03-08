MY_POINT scalePoint(MY_POINT point, SCALING scalingFactor)
{
    MY_POINT newPoint = { (scalingFactor.x) * (point.x),
                        (scalingFactor.y) * (point.y),
                        (scalingFactor.z) * (point.z) };
    return newPoint;
}

MY_POINT translatePoint(MY_POINT point, TRANSLATION translationFactor)
{
    MY_POINT newPoint = { translationFactor.x + point.x,
                        translationFactor.y + point.y,
                        translationFactor.z + point.z };
    return newPoint;
}

// to reflect by x axis : reflectionFactor = {1, -1, 0}
// to reflect by y axis : reflectionFactor = {-1, 1, 0}
MY_POINT reflectPoint(MY_POINT point, REFLECTION reflectionFactor)
{
    MY_POINT newPoint = { reflectionFactor.x * point.x,
                        reflectionFactor.y * point.y,
                        reflectionFactor.z * point.z };
    return newPoint;
}

MY_POINT rotatePoint(MY_POINT point, float rotationAngle)
{
    MY_POINT newPoint = { (cos(rotationAngle) * point.x) + (sin(rotationAngle) * point.y),
                        (0 - (sin(rotationAngle) * point.x)) + (cos(rotationAngle) * point.y),
                        point.z };
    return newPoint;
}
