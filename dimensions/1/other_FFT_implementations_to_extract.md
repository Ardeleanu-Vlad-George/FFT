The DFT of:
    double data[][4] = {
        { 1, 2, 3, 4},
        { 5, 6, 7, 8},
        { 9, 10, 11, 12},
        { 13, 14, 15, 16}
    };
Is:
4x4
\[(136,0)]   \[(-8,8)] \[(-8,-0)] \[(-8,-8)] 
\[(-32,32)]  \[(0,-0)] \[(0,0)]   \[(0,0)] 
\[(-32,-0)]  \[(0,0)]  \[(0,0)]   \[(-0,0)] 
\[(-32,-32)] \[(0,0)]  \[(-0,0)]  \[(-0,0)] 
The DFT of:
2x2
\[(1,0)] \[(2,0)] 
\[(3,0)] \[(4,0)] 
is:
2x2
\[(10,0)] \[(-2,0)] 
\[(-4,0)] \[(0,0)] 
        /*
            You initially tried this code for the data members of 'complex_rgb':
                union{
                    struct{
                        std::complex<double> r,g,b;
                    };
                    struct{
                        std::complex<double> c[3];
                    };
                };
            It didn't work, the compiler complained that std::complex<double> has
            a constructor and therefore shouldn't be allowed inside a "anonymous 
            aggregate". Below you have the exact search phrase that yielded some
            results:
            |c++ solve 'member with constructor not allowed in anonymous aggregate'|
        */
,,BUN
complex_img.cpp
void complex_img::applyMtrxFFT_by_VctrInterpret(
    //variables for the vectorial navigation
    int strtPos, int stepCnt, int stepLen, 
    //variables for applying the FFT
    std::complex<double>* roots, int rootsMultiplier){
    
    //start the InOutEvenOdd temporary variables 
    complex_rgb evnOut, oddOut;
    int evnIdx, oddIdx;
    
    for(int lyrIdx=0, subDftLen=1, rtsCircArithStep=stepCnt/2; lyrIdx<log2(stepCnt); 
            lyrIdx++, subDftLen*=2, rtsCircArithStep/=2){
        for(int subDftIdx=0; subDftIdx<stepCnt/subDftLen; subDftIdx+=2){            
            for(int i=0; i < subDftLen; i++){
                evnIdx=i+subDftIdx*subDftLen;
                oddIdx=evnIdx+subDftLen;

                evnOut=vctrDt[strtPos+evnIdx*stepLen]+
                       vctrDt[strtPos+oddIdx*stepLen]*
                       roots[(evnIdx*rtsCircArithStep)%stepCnt];

                oddOut=vctrDt[strtPos+evnIdx*stepLen]+
                       vctrDt[strtPos+oddIdx*stepLen]*
                       roots[(oddIdx*rtsCircArithStep)%stepCnt];

                vctrDt[strtPos+evnIdx*stepLen]=evnOut;
                vctrDt[strtPos+oddIdx*stepLen]=oddOut;
            }
        }
    }
}




//here we use the 'mtrc' abreviation to a similar use,
//we have the matricial direction (1 - along, or, more precissely, on the columns)
//0 - means along, or, more precissely, on the lines
//The given index states which line/column should be affected
void complex_img::FFT(int mtrxDirection, int mtrxIndex, std::complex<double>* roots){

    
    applyMtrxFFT_by_VctrInterpret(
        mtrxDirection ? mtrxIndex : mtrxIndex*imgDim[1],
        mtrxDirection ? imgDim[0] : imgDim[1],
        mtrxDirection ? imgDim[1] : 1,
        roots,
        mtrxIndex
    );

    swapLinearHalfsMtrx_by_VctrInterpret(
        mtrxDirection ? mtrxIndex : mtrxIndex*imgDim[1],
        mtrxDirection ? imgDim[0] : imgDim[1],
        mtrxDirection ? imgDim[1] : 1        
    );
}

void complex_img::swapLinearHalfsMtrx_by_VctrInterpret(int strtPos, int stepCnt, int stepLen){
    complex_rgb swapTmp;
    for(int i=0; i<stepCnt/2; i++){
        swapTmp=vctrDt[strtPos+i*stepLen];
        vctrDt[strtPos+i*stepLen]=vctrDt[strtPos+(i+stepCnt/2)*stepLen];
        vctrDt[strtPos+(i+stepCnt/2)*stepLen]=swapTmp;
    }
}
complex_img__FFT.cpp

//We need the starting position, the number of steps we will make, the
//length of a step
void complex_img::applyMtrxFFT_by_VctrInterpret(
    //variables for the vectorial navigation
    int strtPos, int stepCnt, int stepLen, 
    //variables for applying the FFT
    std::complex<double>* roots, int rootsMultiplier){
    
    //start the InOutEvenOdd temporary variables 
    complex_rgb evnOut, oddOut;
    int evnIdx, oddIdx;
    
    for(int lyrIdx=0, subDftLen=1, rtsCircArithStep=stepCnt/2; lyrIdx<log2(stepCnt); 
            lyrIdx++, subDftLen*=2, rtsCircArithStep/=2){
        for(int subDftIdx=0; subDftIdx<stepCnt/subDftLen; subDftIdx+=2){            
            for(int i=0; i < subDftLen; i++){
                evnIdx=i+subDftIdx*subDftLen;
                oddIdx=evnIdx+subDftLen;

                evnOut=vctrDt[strtPos+evnIdx*stepLen]+
                       vctrDt[strtPos+oddIdx*stepLen]*
                       roots[(evnIdx*rtsCircArithStep)%stepCnt];

                oddOut=vctrDt[strtPos+evnIdx*stepLen]+
                       vctrDt[strtPos+oddIdx*stepLen]*
                       roots[(oddIdx*rtsCircArithStep)%stepCnt];

                vctrDt[strtPos+evnIdx*stepLen]=evnOut;
                vctrDt[strtPos+oddIdx*stepLen]=oddOut;
            }
        }
    }
}

void complex_img::swapLinearHalfsMtrx_by_VctrInterpret(int strtPos, int stepCnt, int stepLen){
    complex_rgb swapTmp;
    for(int i=0; i<stepCnt/2; i++){
        swapTmp=vctrDt[strtPos+i*stepLen];
        vctrDt[strtPos+i*stepLen]=vctrDt[strtPos+(i+stepCnt/2)*stepLen];
        vctrDt[strtPos+(i+stepCnt/2)*stepLen]=swapTmp;
    }
}

//here we use the 'mtrc' abreviation to a similar use,
//we have the matricial direction (1 - along, or, more precissely, on the columns)
//0 - means along, or, more precissely, on the lines
//The given index states which line/column should be affected
void complex_img::FFT(int mtrxDirection, int mtrxIndex, std::complex<double>* roots){

    
    applyMtrxFFT_by_VctrInterpret(
        mtrxDirection ? mtrxIndex : mtrxIndex*imgDim[1],
        mtrxDirection ? imgDim[0] : imgDim[1],
        mtrxDirection ? imgDim[1] : 1,
        roots,
        mtrxIndex
    );
/*
    swapLinearHalfsMtrx_by_VctrInterpret(
        mtrxDirection ? mtrxIndex : mtrxIndex*imgDim[1],
        mtrxDirection ? imgDim[0] : imgDim[1],
        mtrxDirection ? imgDim[1] : 1        
    );
*/
}
FFT.cpp
#include "FFT.hpp"
<<<<<<< HEAD
#include "helper.hpp"
<<<<<<< HEAD
=======
void to_rm_DFT(complex_img& ci, sf::Image& sfi){
    int order=ci.imgDim[0],
        orderHlf=orderHlf/2;
    
    unsigned char *imgPtr=(unsigned char*)sfi.getPixelsPtr();

    std::complex<double> tmp, sum[3];
    
    #define EXPR(clr)\
        tmp=std::complex<double>(imgPtr[(a+b*order)*4+clr], 0.);\
        sum[clr]+=tmp*to_rm_exp_arg(i*a+j*b, order)

    //iterate over the pixel of the complex image
    for(int i=-orderHlf; i < orderHlf; i++)
        for(int j=-orderHlf; j < orderHlf; j++){
            sum[0]=sum[1]=sum[2]=std::complex<double>(0., 0.);
            
            //iterate over the pixels of the image
            for(int a=0;a<order;a++)
                for(int b=0;b<order;b++){
                    EXPR(0); EXPR(1); EXPR(2);
                }

            ci.mtrxDt[orderHlf+i][orderHlf+j]=complex_rgb(sum);
        }
    
    #undef EXPR
}

void FFT(complex_img& cpxImg){
    //0 - the roots for a line
    //1 - the roots for a column
    std::complex<double>* rts[] = {
        computeRootsOfUnity(cpxImg.imgDim[1]),
        computeRootsOfUnity(cpxImg.imgDim[0])
    };

    //OBS: The number of columns determines the number of elements on a line 
    //and vice-versa, that explains the inversion
    
    //columns
    for(int i=0; i<cpxImg.imgDim[1]; i++)
        cpxImg.FFT(1, i, rts[1]);
    //lines
    for(int i=0; i<cpxImg.imgDim[0]; i++)
        cpxImg.FFT(0, i, rts[0]);
}
main.cpp
//the "butterfly" algorithm inside a matrix
void MtrxInOutEvenOddFFTAdd(
                            //relevant indexes
                            int lnIdxEvn, int lnIdxOdd,
                            int clIdxEvn, int clIdxOdd,
                            
                            //used in calculations
                            int ord, 
                            int pwrStep,
                            
                            //manipulated data
                            double mtrx[][][][],
                            double rts[][]){
    int rtsEvnIdx = lnIdxEvn == lnIdxOdd ? clIdxEvn : lnIdxEvn,
        rtsOddIdx = lnIdxEvn == lnIdxOdd ? clIdxOdd : lnIdxOdd;

    #define ADD_CMPLX_RGB(cmp)\
        
    #undef ADD_CMPLX_RGB
}

void FFTonColumn(int ord, double vls[][][][], int cl, double rts[][]){
    int evnIdx, oddIdx;

    for(int lyrIdx=0, seqLen=1, pwrStep=ord/2; lyrIdx<log2(ord); 
            lyrIdx++, seqLen*=2, pwrStep/=2){
        for(int subDftIdx=0; subDftIdx<ord/seqLen; subDftIdx+=2){            
            for(int i=0; i < seqLen; i++){
                //to replace
                evnIdx=i+subDftIdx*seqLen;
                oddIdx=evnIdx+seqLen;

                evnOut=result[evnIdx]+rtsOfUnit[(evnIdx*pwrStep)%N]*result[oddIdx];
                oddOut=result[evnIdx]+rtsOfUnit[(oddIdx*pwrStep)%N]*result[oddIdx];

                result[evnIdx]=evnOut;
                result[oddIdx]=oddOut;
                //to replace
            }
        }
    }

    rearrangeColumn(ord, vls, cl);
}
