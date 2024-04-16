#define __ARM_2D_IMPL__

#include "arm_2d.h"
#include "__arm_2d_impl.h"

#ifdef   __cplusplus
extern "C" {
#endif

#if defined(__clang__)
#   pragma clang diagnostic ignored "-Wunknown-warning-option"
#   pragma clang diagnostic ignored "-Wreserved-identifier"
#   pragma clang diagnostic ignored "-Wincompatible-pointer-types-discards-qualifiers"
#   pragma clang diagnostic ignored "-Wmissing-variable-declarations"
#   pragma clang diagnostic ignored "-Wcast-qual"
#   pragma clang diagnostic ignored "-Wcast-align"
#   pragma clang diagnostic ignored "-Wextra-semi-stmt"
#   pragma clang diagnostic ignored "-Wsign-conversion"
#   pragma clang diagnostic ignored "-Wunused-function"
#   pragma clang diagnostic ignored "-Wimplicit-int-float-conversion"
#   pragma clang diagnostic ignored "-Wdouble-promotion"
#   pragma clang diagnostic ignored "-Wunused-parameter"
#   pragma clang diagnostic ignored "-Wimplicit-float-conversion"
#   pragma clang diagnostic ignored "-Wimplicit-int-conversion"
#   pragma clang diagnostic ignored "-Wtautological-pointer-compare"
#   pragma clang diagnostic ignored "-Wsign-compare"
#   pragma clang diagnostic ignored "-Wmissing-prototypes"
#   pragma clang diagnostic ignored "-Wgnu-zero-variadic-macro-arguments"
#   pragma clang diagnostic ignored "-Wswitch-enum"
#   pragma clang diagnostic ignored "-Wswitch"
#   pragma clang diagnostic ignored "-Wdeclaration-after-statement"
#elif defined(__IS_COMPILER_ARM_COMPILER_5__)
#   pragma diag_suppress 174,177,188,68,513,144
#endif

#if 1
__OVERRIDE_WEAK
void __arm_2d_impl_rgb565_filter_iir_blur(
                            uint16_t *__RESTRICT phwTarget,
                            int16_t iTargetStride,
                            arm_2d_region_t *__RESTRICT ptValidRegionOnVirtualScreen,
                            arm_2d_region_t *ptTargetRegionOnVirtualScreen,
                            uint8_t chBlurDegree,
                            arm_2d_scratch_mem_t *ptScratchMemory)
{


}

__OVERRIDE_WEAK
void __arm_2d_impl_gray8_filter_iir_blur(
                            uint8_t *__RESTRICT pchTarget,
                            int16_t iTargetStride,
                            arm_2d_region_t *__RESTRICT ptValidRegionOnVirtualScreen,
                            arm_2d_region_t *ptTargetRegionOnVirtualScreen,
                            uint8_t chBlurDegree,
                            arm_2d_scratch_mem_t *ptScratchMemory)
{
}
__OVERRIDE_WEAK
void __arm_2d_impl_cccn888_filter_iir_blur(
                            uint32_t *__RESTRICT pwTarget,
                            int16_t iTargetStride,
                            arm_2d_region_t *__RESTRICT ptValidRegionOnVirtualScreen,
                            arm_2d_region_t *ptTargetRegionOnVirtualScreen,
                            uint8_t chBlurDegree,
                            arm_2d_scratch_mem_t *ptScratchMemory)
{
	int8x16_t v_sub;
	uint32x4_t v_previous_init;
	uint8x16_t v_previous;
	uint8x16_t v_data;
	chBlurDegree = 255 - chBlurDegree; 
	int8x16_t v_ratio = vdupq_n_s8(chBlurDegree>>1);
	uint16_t iHeight = ptValidRegionOnVirtualScreen->tSize.iHeight;
	uint16_t iWidth = ptValidRegionOnVirtualScreen->tSize.iWidth;

	__arm_2d_iir_blur_acc_cccn888_t *ptStatusH = NULL;
  __arm_2d_iir_blur_acc_cccn888_t *ptStatusV = NULL;
	if (NULL != (void *)ptScratchMemory->pBuffer) {
        ptStatusH = (__arm_2d_iir_blur_acc_cccn888_t *)ptScratchMemory->pBuffer;
        ptStatusV = ptStatusH + ptTargetRegionOnVirtualScreen->tSize.iWidth;
    }

    /* calculate the offset between the target region and the valid region */
    arm_2d_location_t tOffset = {
        .iX = ptValidRegionOnVirtualScreen->tLocation.iX - ptTargetRegionOnVirtualScreen->tLocation.iX,
        .iY = ptValidRegionOnVirtualScreen->tLocation.iY - ptTargetRegionOnVirtualScreen->tLocation.iY,
    };
	
	#if 1
	uint32x4_t v_offset;
	v_offset[0] = 0;
	v_offset[1] = iTargetStride<<2;
	v_offset[2] = (iTargetStride<<3);
	v_offset[3] = (iTargetStride<<3) +(iTargetStride<<2);
	for(int y = 0; y < (iHeight - (iHeight&3)-1); y+=4)
	{
		v_previous_init = vldrwq_gather_offset((&pwTarget[y*iTargetStride]), v_offset);
		v_previous  = vreinterpretq_u8(v_previous_init);
		v_previous = vshrq(v_previous, 1);

		for(int x = 0; x < iWidth; x++)
		{
			v_previous_init = vldrwq_gather_offset(&pwTarget[y*iTargetStride+x], v_offset);
			v_data = vreinterpretq_u8(v_previous_init);
			v_data = vshrq(v_data, 1);
			v_sub = vsubq(v_data, v_previous);
			v_sub = vqdmulhq(v_sub, v_ratio);
			v_previous = vaddq((int8x16_t)v_previous, v_sub);
			v_sub = vshlq_n(v_previous, 1);
			v_previous_init = vreinterpretq_u32(v_sub);
			vstrwq_scatter_offset_u32(&pwTarget[y*iTargetStride + x], v_offset, v_previous_init);
		}
	}
	
	if((iHeight&3) !=0)
	{
		int y = iHeight - (iHeight&3);
		mve_pred16_t v_pred = vctp8q(((iHeight&3)-1));

		v_previous_init = vldrwq_gather_offset_z(&pwTarget[y*iTargetStride], v_offset, v_pred);
		v_previous  = vreinterpretq_u8(v_previous_init);
		v_previous = vshrq(v_previous, 1);
		for(int x = 1; x < iWidth; x++)
		{
			v_previous_init = vldrwq_gather_offset_z(&pwTarget[y*iTargetStride+x], v_offset, v_pred);
			v_data = vreinterpretq_u8(v_previous_init);
			v_data = vshrq(v_data, 1);
			v_sub = vsubq(v_data, v_previous);
			v_sub = vqdmulhq(v_sub, v_ratio);
			v_previous = vaddq((int8x16_t)v_previous, v_sub);
			v_sub = vshlq_n(v_previous, 1);
			v_previous_init = vreinterpretq_u32(v_sub);
			vstrwq_scatter_offset_p(&pwTarget[y*iTargetStride + x], v_offset, v_previous_init, v_pred);
		}
	}
	#endif
	//column x4
	#if 1
	for(int x = 0; x < iWidth - (iWidth&3)-1; x+=4)
	{
		v_previous_init = vld1q(&pwTarget[x]);
		v_previous  = vreinterpretq_u8(v_previous_init);
		v_previous = vshrq(v_previous, 1);
		for(int y = 1; y < iHeight; y++)
		{
			v_previous_init = vld1q(&pwTarget[y*iTargetStride+x]);
			v_data = vreinterpretq_u8(v_previous_init);
			v_data = vshrq(v_data, 1);
			v_sub = vsubq(v_data, v_previous);
			v_sub = vqdmulhq(v_sub, v_ratio);
			v_previous = vaddq((int8x16_t)v_previous, v_sub);
			v_sub = vshlq_n(v_previous, 1);
			vst1q((int8_t*)&pwTarget[y*iTargetStride + x], v_sub);
		}
	}
	if((iWidth&3)!=0)
	{
		int x = iWidth - (iWidth&3);
		mve_pred16_t v_pred = vctp32q(((iWidth&3)));
		v_previous_init = vld1q_z(&pwTarget[x], v_pred);
		v_previous  = vreinterpretq_u8(v_previous_init);
		v_previous = vshrq(v_previous, 1);
		for(int y = 1; y < iHeight; y++)
		{
			v_previous_init = vld1q_z(&pwTarget[y*iTargetStride+x], v_pred);
			v_data = vreinterpretq_u8(v_previous_init);
			v_data = vshrq(v_data, 1);
			v_sub = vsubq(v_data, v_previous);
			vqdmulhq(v_sub, v_ratio);
			v_previous = vaddq((int8x16_t)v_previous, v_sub);
			v_sub = vshlq_n(v_previous, 1);
			v_previous_init = vreinterpretq_u32(v_sub);
			vst1q_p((int8_t*)&pwTarget[y*iTargetStride + x], v_sub, v_pred);
		}
	}
	#endif
}
#endif
#ifdef   __cplusplus
}
#endif