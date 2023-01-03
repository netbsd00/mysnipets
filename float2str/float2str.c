/**********************************************************************
*
*    Filename        : float2str.c
*    Author          : hwyi
*    Version         : 1.0
*    Description     : convert float to string
*
*   ==================================================================
*   DATE                AUTHOR             NOTE
*   ------------------------------------------------------------------
*   2023.01.03          hwyi               최초 생성
*
***********************************************************************/
#include <math.h>

static char float_str[32];
char *floatToStr(float f)
{
    #define precision 6  //precision for decimal digits

    float ff;
	int a,b,c,k,l=0,m,i=0;
	char *str = float_str;
	ff = f;
	
	// check for negetive float
	if(f<0.0)
	{
		
		str[i++]='-';
		f*=-1;
	}
	
	a=(int)f;	// extracting whole number
	f-=a;	// extracting decimal part
	k = precision;
	
	// number of digits in whole number
	while(k>-1)
	{
		l = (int)pow(10,k);
		m = a/l;
		if(m>0)
		{
			break;
		}
	k--;
	}

	// number of digits in whole number are k+1
	
	/*
	extracting most significant digit i.e. right most digit , and concatenating to string
	obtained as quotient by dividing number by 10^k where k = (number of digit -1)
	*/
	if(k == -1)
    {
        str[i++] = '0';
    }

	for(l=k+1;l>0;l--)
	{
		b = (int)pow(10,l-1);
		c = a/b;
		str[i++]=(char)c+48;
		a%=b;
	}
	str[i++] = '.';
	
	/* extracting decimal digits till precision */

	for(l=0;l<precision;l++)
	{
		f*=10.0;
		b = (int)f;
		str[i++]=(char)b+48;
		f-=b;
	}

	str[i]='\0';

	// printf("\n orignal printf %f\n",ff);
	// printf("\n float string %s\n",str);


	return str;
}
