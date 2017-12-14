//
//  LPFilter.cpp
//  Yunit_3Wheels
//
//  Created by y6tada_mac on 2016/03/18.
//  Copyright © 2016年 y6tada_mac. All rights reserved.
//

#include "LPFilter.hpp"

static int time_ct = 0;
static int time_ct_doubleFunc = 0;

LPFilter::LPFilter(int setStep)
{
	step			= (setStep > ARRAY_NUM)? ARRAY_NUM : setStep;
	__isEnalbe__	= (setStep) ? true : false;
}

int LPFilter::setMAV (int setData)
{
	if (__isEnalbe__) {
		
		// ----- 配列のアクセス位置をカウントアップ ----- //
		if (time_ct < step)
			time_ct ++;
		else
			time_ct = 0;
		
		// ----- 代入 ----------------------- //
		dataArray[time_ct] = setData;
		
		// ---- dataArray合計 --------------- //
		int sum_dataArray = 0;
		
		for (int i = 0; i < step; ++i) {
			sum_dataArray += dataArray[i];
		}
		// ----- 平均化 --------------------- //
		sum_dataArray /= step;
		return sum_dataArray;
	}
	else {
		// stepが設定されていない
		pc.printf("Error HPFilter Disable \n");
	}
	
	return 0;
}

double LPFilter::setMAV_double (double setData)
{
	if (__isEnalbe__) {
		
		// ----- 配列のアクセス位置をカウントアップ ----- //
		if (time_ct_doubleFunc < step)
			time_ct_doubleFunc ++;
		else
			time_ct_doubleFunc = 0;
		
		// ----- 代入 ----------------------- //
		dataArray_double[time_ct_doubleFunc] = setData;
		
		// ---- dataArray合計 --------------- //
		double sum_dataArray = 0;
		
		for (int i = 0; i < step; ++i) {
			sum_dataArray += dataArray_double[i];
		}
		// ----- 平均化 --------------------- //
		return sum_dataArray / (double)step;
	}
	else {
		// stepが設定されていない
		pc.printf("Error HPFilter Disable \n");
	}
	
	return 0;
}