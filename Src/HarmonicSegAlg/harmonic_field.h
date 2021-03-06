#ifndef CHARMONIC_FIELD_H
#define CHARMONIC_FIELD_H
#include"Eigen/Core"
#include <Eigen/Sparse>
#include<iostream>
#include<vector>
#include"../DataColle/custom_openmesh_type.h"
#include"prereq.h"
class HARMONICSEGALG_CLASS CHarmonicFieldSeg
{
protected:
	bool IsConcave(COpenMeshT &mesh, COpenMeshT::VertexHandle vh);
	void GetConcavityAwareLaplacianMatrix(COpenMeshT &mesh, std::vector<Eigen::Triplet<double>>&triplets);
	
public:
	void ComputeConcavityAwareHarmonicField(COpenMeshT&mesh, std::vector<std::pair<COpenMeshT::VertexHandle, double>>&cons,Eigen::VectorXd &res_u);
	void SegOneTeeth(COpenMeshT&mesh, std::vector<COpenMeshT::VertexHandle>&vhs, std::vector<COpenMeshT::VertexHandle>&res_teeth);
	void SegTwoTooth(COpenMeshT&mesh, std::vector<COpenMeshT::VertexHandle>&vhs0, std::vector<COpenMeshT::VertexHandle>&vhs1, std::vector<COpenMeshT::VertexHandle>&res_teeth0, std::vector<COpenMeshT::VertexHandle>&res_teeth1);
	void RefineSegTwoTooth(COpenMeshT &mesh, std::vector<COpenMeshT::VertexHandle>&vhs0, std::vector<COpenMeshT::VertexHandle>&vhs1);
	void SegTwoSet(COpenMeshT&mesh, std::vector<COpenMeshT::VertexHandle>&vhs0, std::vector<COpenMeshT::VertexHandle>&vhs1, std::vector<COpenMeshT::VertexHandle>&res_vhs0, std::vector<COpenMeshT::VertexHandle>&res_vhs1);
	void SegToothGingiva(COpenMeshT&mesh, std::vector<COpenMeshT::VertexHandle>&vhs_tooth, std::vector<COpenMeshT::VertexHandle>&vhs_gingiva, std::vector<COpenMeshT::VertexHandle>&res_tooth, std::vector<COpenMeshT::VertexHandle>&res_gingiva);
	void RefineToothGingivaSeg(COpenMeshT&mesh, std::vector<COpenMeshT::VertexHandle>&tooth_vhs, std::vector<COpenMeshT::VertexHandle>&res_tooth);
	void RefineTeethGingivaSeg(COpenMeshT&mesh, std::vector<COpenMeshT::VertexHandle>&teeth_vhs, std::vector<COpenMeshT::VertexHandle>&res_teeth);
	void RefineTeethGingivaSeg(COpenMeshT &mesh, std::vector<int>&teeth_mark);//teeth_mark:mark of each teeth, -1 means gingiva
};

#endif