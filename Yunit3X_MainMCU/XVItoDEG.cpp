//
//  XVItoDEG.cpp
//  Yunit_3Wheels_2
//
//  Created by y6tada_mac on 2016/03/26.
//  Copyright © 2016年 y6tada_mac. All rights reserved.
//

#include "XVItoDEG.hpp"

int XVItoDEG (int XVI)
{
	switch (XVI)
	{
		case 0:
			return 11.25;
		case 1:
			return 22.5 * 1;
		case 2:
			return 22.5 * 2;
		case 3:
			return 22.5 * 3;
		case 4:
			return 22.5 * 4;
		case 5:
			return 22.5 * 5;
		case 6:
			return 22.5 * 6;
		case 7:
			return 22.5 * 7;
		case 8:
			return 22.5 * -7;
		case 9:
			return 22.5 * -6;
		case 10:
			return 22.5 * -5;
		case 11:
			return 22.5 * -4;
		case 12:
			return 22.5 * -3;
		case 13:
			return 22.5 * -2;
		case 14:
			return 22.5 * -1;
		case 15:
			return -11.25;
	}
	return 0;
}