#include "kalmanFilter.h"

kalmanFilter::kalmanFilter(float _a,float _c, float _H, float _sigma){
	a = _a;
	c = _c;
	H = _H;
	sigma = _sigma;
}

void kalmanFilter::Init(float _R, float _pa, float _xa){	
	R = _R;
	pa = _pa;
	xa = _xa;
}

float kalmanFilter::Compute(float new_data){
	//Propagation process
	x_p = a*xa;
	p = a*pa*a+c*sigma*c;

	//Update process
	KalmanK = p*H/(H*p*H+R);	//Kalman gain
	pa = p - KalmanK*H*p;	//covariance propagation
	xa = x_p + KalmanK*(new_data-H*x_p);

	return xa;
}