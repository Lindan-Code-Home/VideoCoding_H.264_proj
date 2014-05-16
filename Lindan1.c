
/*!
 *************************************************************************************
 * \file image.c
 *
 * \brief
 *    Code one image/slice
 *
 * \author
 *    Lindan Tian 3/30/2013
 *
 *************************************************************************************
 */


#include "Lindan1.h"


void JudgeforSkipInter( VideoParameters *p_Vid)
 {   
     //FILE *TOsee;
	  LindanDiff=0;
     //int p1,p2,jofMB,iofMB,jofFrame,iofFrame;
     //imgpel minus;
	 if(p_Vid->qp==28)
		 w=1.2;
	 if(p_Vid->qp==32)
		 w=1.0;
	 if(p_Vid->qp==36)
		 w=0.8;
	 if(p_Vid->qp==40)
		 w=0.6;

      //JudgeofSkipInterByLindan=malloc(n,size); *
      if(Numofframe_Lindan)  
	  {for(i=0;i<18;i++)
		 for(j=0;j<22;j++)
		 {JudgeofSkipInterByLindan[i*22+j]=0;
	      DiffofMB[i*22+j]=0;
	     }
	  
	     for(i=0;i<18;i++)
			for(j=0;j<22;j++)
		
			{
				for(i2=0;i2<16;i2++)
					for(j2=0;j2<16;j2++)
					{   
						p1=p_Vid->imgData0.frm_data[0][0][(i*16+i2)*352+j*16+j2];
						p2=PreviousOriginalFrame[(i*16+i2)*352+j*16+j2];
						DiffofMB[i*22+j]+=abs(p1-p2);
					}
				LindanDiff+=DiffofMB[i*22+j]/396;
			}

	  for(i=0;i<18;i++)
      for(j=0;j<22;j++)
	  {if(DiffofMB[i*22+j]*w<= LindanDiff)
	    JudgeofSkipInterByLindan[i*22+j]=1;
	  }}

       LindanDiff=0; 
	  
	 Numofframe_Lindan++;
	  
      memcpy(&PreviousOriginalFrame[0], &p_Vid->imgData0.frm_data[0][0][0], 352*288 * sizeof (imgpel));
    //TOsee= fopen("abc.dat","w");
	 //if(TOsee == NULL){printf("error to open");exit(1);}
	  //fwrite(PreviousOriginalFrame,sizeof(imgpel),352*288, TOsee);
	  //fwrite(&p_Vid->imgData0.frm_data[0][0][0],sizeof(imgpel),352*288, TOsee);
	  //fclose(TOsee);
	  //f(Tosee,"%d %d\n",mv_block->mv->mv_x/4,mv_block->mv->mv_y/4);
// modified by Lindan

  }
