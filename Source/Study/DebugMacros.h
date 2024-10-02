#pragma once
#include "DrawDebugHelpers.h"

#define DRAW_SPHERE(Position) if (GetWorld()) DrawDebugSphere(GetWorld(), Position, 25.f, 12, FColor::Cyan, true)
#define DRAW_SPHERE_SingleFrame(Position) if (GetWorld()) DrawDebugSphere(GetWorld(), Position, 25.f, 12, FColor::Cyan, false, -1.0f);
#define DRAW_LINE(StartPosition, EndPosition) if (GetWorld()) DrawDebugLine(GetWorld(), StartPosition, EndPosition, FColor::Cyan, true, -1.0f, 0.0f, 1.0f)
#define DRAW_LINE_SingleFrame(StartPosition, EndPosition) if (GetWorld()) DrawDebugLine(GetWorld(), StartPosition, EndPosition, FColor::Cyan, false, -1.0f, 0.0f, 1.0f)
#define DRAW_POINT(Position) if(GetWorld()) DrawDebugPoint(GetWorld(), Position, 15.0f, FColor::Cyan, true)
#define DRAW_POINT_SingleFrame(Position) if(GetWorld()) DrawDebugPoint(GetWorld(), Position, 15.0f, FColor::Cyan, false, -1.0f)
#define DRAW_VECTOR(StartPosition, EndPosition) if (GetWorld()) \
{ \
	DrawDebugLine(GetWorld(), StartPosition, EndPosition, FColor::Cyan, true, -1.0f, 0.0f, 1.0f); \
	DrawDebugPoint(GetWorld(), EndPosition, 15.0f, FColor::Cyan, true); \
}
#define DRAW_VECTOR_SingleFrame(StartPosition, EndPosition) if (GetWorld()) \
{ \
	DrawDebugLine(GetWorld(), StartPosition, EndPosition, FColor::Cyan, false, -1.0f, 0.0f, 1.0f); \
	DrawDebugPoint(GetWorld(), EndPosition, 15.0f, FColor::Cyan, false, -1.0f); \
}