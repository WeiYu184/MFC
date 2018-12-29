#include<iostream>
typedef struct 
{
	float m_x;
	float m_y;
	float m_z;
	int m_connect;
}point;

#pragma once
class CGrp
{
public:
	CGrp(void);
	~CGrp(void);
	int m_linetype;
	int m_color;
	int m_ptnum;
	point* m_pt;

    void AddPtToGrp(point pt);
	bool DrawGrp(char* filename, CGrp** pGrps);
	bool ReadGrpFile(char* filename, CGrp** pGrps, int* num);
	bool WriteGrpFile(char* filename, CGrp* pGrps, int num);
	
};

