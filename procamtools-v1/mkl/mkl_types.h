/*******************************************************************************
!                             INTEL CONFIDENTIAL
!   Copyright(C) 1999-2004 Intel Corporation. All Rights Reserved.
!   The source code contained  or  described herein and all documents related to
!   the source code ("Material") are owned by Intel Corporation or its suppliers
!   or licensors.  Title to the  Material remains with  Intel Corporation or its
!   suppliers and licensors. The Material contains trade secrets and proprietary
!   and  confidential  information of  Intel or its suppliers and licensors. The
!   Material  is  protected  by  worldwide  copyright  and trade secret laws and
!   treaty  provisions. No part of the Material may be used, copied, reproduced,
!   modified, published, uploaded, posted, transmitted, distributed or disclosed
!   in any way without Intel's prior express written permission.
!   No license  under any  patent, copyright, trade secret or other intellectual
!   property right is granted to or conferred upon you by disclosure or delivery
!   of the Materials,  either expressly, by implication, inducement, estoppel or
!   otherwise.  Any  license  under  such  intellectual property  rights must be
!   express and approved by Intel in writing.
!
!*******************************************************************************
!  Content:
!      Intel(R) Math Kernel Library (MKL) types definition
!******************************************************************************/

#ifndef _MKL_TYPES_H_
#define _MKL_TYPES_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* Complex type (single precision). */
typedef
struct _MKL_Complex8 {
    float    real;
    float    imag;
} MKL_Complex8;

/* Complex type (double precision). */
typedef
struct _MKL_Complex16 {
    double    real;
    double    imag;
} MKL_Complex16;

typedef
struct {
    int       MajorVersion;
    int       MinorVersion;
    char*     ProductStatus;
    char *    BuildDate;
    char *    Processor;
    char *    Platform;
} MKLVersion;

#ifdef __cplusplus
} 
#endif /* __cplusplus */

#endif /* _MKL_TYPES_H_ */
