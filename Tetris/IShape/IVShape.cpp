#include "IVShape.h"
#include "IHShape.h"
#include "../Common.h"
#include <iostream>
IVShape::IVShape(int parentX, int parentY) : Component(parentX, parentY){
	m_location[0][0] = true;
	m_location[1][0] = true;
	m_location[2][0] = true;
}
IVShape::~IVShape(){}
void IVShape::ChangeShapeDirection(Component*& shapeDirection){
	int parentX = m_parentX;
	int parentY = m_parentY;
	//Clean();
	delete shapeDirection;

	shapeDirection = new IHShape(--parentX, parentY);
}
//std::vector<Point*> IVShape::GetUpBorder(){
//	std::vector<Point*> upBorder;
//	Point* lfirst = new Point(m_parentX, m_parentY);
//	upBorder.push_back(lfirst);
//
//	return upBorder;
//}
std::vector<Point*> IVShape::GetLeftBorder(){

	std::vector<Point*> leftBorder;
	Point* lfirst = new Point(m_parentX - 1, m_parentY);
	Point* lsecond = new Point(m_parentX - 1, m_parentY + 1);
	Point* lthird = new Point(m_parentX - 1, m_parentY + 2);
	leftBorder.push_back(lfirst);
	leftBorder.push_back(lsecond);
	leftBorder.push_back(lthird);

	return leftBorder;
}
std::vector<Point*> IVShape::GetBottomBorder(){

	std::vector<Point*> bottomLine;
	Point* bfirst = new Point(m_parentX, m_parentY + 2 + 1);
	bottomLine.push_back(bfirst);

	return bottomLine;
}

std::vector<Point*> IVShape::GetRightBorder(){

	std::vector<Point*> rightBorder;
	Point* rfirst = new Point(m_parentX + 1, m_parentY);
	Point* rsecond = new Point(m_parentX + 1, m_parentY + 1);
	Point* rthird = new Point(m_parentX + 1, m_parentY + 2);
	rightBorder.push_back(rfirst);
	rightBorder.push_back(rsecond);
	rightBorder.push_back(rthird);

	return rightBorder;
}
std::vector<Point*> IVShape::GetLocation() const{
	std::vector<Point*> temp;
	temp.push_back(new Point(m_parentX, m_parentY));
	temp.push_back(new Point(m_parentX, m_parentY + 1));
	temp.push_back(new Point(m_parentX, m_parentY + 2));

	return temp;
}
void IVShape::Display(){
	for (int y = 0; y < 3; ++y){
		for (int x = 0; x < 1; ++x){
			if (m_location[y][x]){
				CursorToPos(m_parentX + x, m_parentY + y);
				std::cout << "*";
			}
		}
	}
}
void IVShape::Clean(){
	for (int y = 0; y < 3; ++y){
		for (int x = 0; x < 1; ++x){
			if (m_location[y][x]){
				CursorToPos(m_parentX + x, m_parentY + y);
				std::cout << " ";
			}
		}
	}
}