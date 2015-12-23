#ifndef BLUESCREEN_VECTOR_H
#define BLUESCREEN_VECTOR_H

struct vec2
{
    float X;
    float Y;
};

vec2 operator*(vec2 A, float B)
{
    vec2 Result;
    Result.X = A.X * B;
    Result.Y = A.Y * B;
    return(Result);
}

vec2 operator-(vec2 A)
{
    vec2 Result;
    Result.X = -A.X;
    Result.Y = -A.Y;
    return(Result);
}

vec2 operator+(vec2 A, vec2 B)
{
    vec2 Result;
    Result.X = A.X + B.X;
    Result.Y = A.Y + B.Y;
    return(Result);
}

bool operator==(vec2 A, vec2 B)
{
    return (A.X == B.X && A.Y == B.Y);
}

float operator^(vec2 A, vec2 B)
{
    return A.X * B.X + A.Y * B.Y;
}

vec2 operator-(vec2 A, vec2 B)
{
    vec2 Result;
    Result.X = A.X - B.X;
    Result.Y = A.Y - B.Y;
    return(Result);
}

vec2 MakeVec(float X, float Y)
{
    vec2 Result = {X,Y};
    return Result;
}

#endif