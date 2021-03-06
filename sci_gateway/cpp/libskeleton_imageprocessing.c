#ifdef __cplusplus
extern "C" {
#endif
#include <mex.h> 
#include <sci_gateway.h>
#include <api_scilab.h>
#include <MALLOC.h>
static int direct_gateway(char *fname,void F(void)) { F();return 0;};
extern Gatefunc opencv_imread;
extern Gatefunc opencv_bwlookup;
extern Gatefunc opencv_imboxfilt;
extern Gatefunc opencv_imapplymatrix;
extern Gatefunc opencv_integralImage;
static GenericTable Tab[]={
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_imread,"imread"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_bwlookup,"bwlookup"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_imboxfilt,"imboxfilt"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_imapplymatrix,"imapplymatrix"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_integralImage,"integralImage"},
};
 
int C2F(libskeleton_imageprocessing)()
{
  Rhs = Max(0, Rhs);
  if (*(Tab[Fin-1].f) != NULL) 
  {
     if(pvApiCtx == NULL)
     {
       pvApiCtx = (StrCtx*)MALLOC(sizeof(StrCtx));
     }
     pvApiCtx->pstName = (char*)Tab[Fin-1].name;
    (*(Tab[Fin-1].f))(Tab[Fin-1].name,Tab[Fin-1].F);
  }
  return 0;
}
#ifdef __cplusplus
}
#endif
