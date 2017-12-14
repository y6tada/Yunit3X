//
//  LPFilter.hpp
//  Yunit_3Wheels
//
//  Created by y6tada_mac on 2016/03/18.
//  Copyright © 2016年 y6tada_mac. All rights reserved.
//

#ifndef LPFilter_hpp
#define LPFilter_hpp

#include "mbed.h"

#define ARRAY_NUM 40

extern Serial pc;

class LPFilter {
	
	bool __isEnalbe__;
	
	int step;
	int	dataArray[ARRAY_NUM];
	
	double	dataArray_double[ARRAY_NUM];
	
public:
	LPFilter	(int setStep);
	int		setMAV	(int setData);
	double	setMAV_double (double setData);
};

#endif /* LPFilter_hpp */
