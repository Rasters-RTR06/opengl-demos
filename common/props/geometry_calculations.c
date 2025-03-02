struct MY_POINT scalePoint(struct MY_POINT point, struct MY_POINT scalingFactor)
{
    struct MY_POINT newPoint = { (scalingFactor.x) * (point.x),
                                 (scalingFactor.y) * (point.y),
                                 (scalingFactor.z) * (point.z) };
    return newPoint;
}

struct MY_POINT translatePoint(struct MY_POINT point, struct MY_POINT translationFactor)
{
    struct MY_POINT newPoint = { translationFactor.x + point.x,
                                 translationFactor.y + point.y,
                                 translationFactor.z + point.z };
    return newPoint;
}

// to reflect by x axis : reflectionFactor = {1, -1, 0}
// to reflect by y axis : reflectionFactor = {-1, 1, 0}
struct MY_POINT reflectPoint(struct MY_POINT point, struct MY_POINT reflectionFactor)
{
    struct MY_POINT newPoint = { reflectionFactor.x * point.x,
                                 reflectionFactor.y * point.y,
                                 reflectionFactor.z * point.z };
    return newPoint;
}
