/* ====================================================================
 * Copyright (c) 1996-2000 Carnegie Mellon University.  All rights 
 * reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer. 
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *
 * This work was supported in part by funding from the Defense Advanced 
 * Research Projects Agency and the National Science Foundation of the 
 * United States of America, and the CMU Sphinx Speech Consortium.
 *
 * THIS SOFTWARE IS PROVIDED BY CARNEGIE MELLON UNIVERSITY ``AS IS'' AND 
 * ANY EXPRESSED OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, 
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL CARNEGIE MELLON UNIVERSITY
 * NOR ITS EMPLOYEES BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, 
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY 
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * ====================================================================
 *
 */
/*********************************************************************
 *
 * File: s3io.h
 * 
 * Description: 
 *    Open, read and write files conforming to S3 conventions
 *
 * Author: 
 *    Eric Thayer
 *********************************************************************/

#ifndef S3IO_H
#define S3IO_H
#ifdef __cplusplus
extern "C" {
#endif
#if 0
}
#endif


#include <s3/prim_type.h>

#include <stdio.h>
#include <stdlib.h>

FILE *
s3open(const char *file_name,
       const char *mode,
       uint32 *swap);

void
s3clr_fattr(void);

void 
s3get_fattr(char ***out_attrib,
	    char ***out_value);

char *
s3get_gvn_fattr(char *attrib);

void
s3add_fattr(char *attrib,
	    char *value,
	    int dup);

/* read/write calls.  Patterned after fread/fwrite */
size_t
s3read(void *pointer,
       size_t size,
       size_t num_items,
       FILE *stream,
       uint32 swap,
       uint32 *chksum);

size_t
s3write(const void *pointer,
	size_t size,
	size_t num_items,
	FILE *stream,
	uint32 *chksum);


int
s3close(FILE *fp);

/* Array read/write calls */
int32
s3read_3d(void ****arr,
	  size_t e_sz,
	  uint32 *d1,
	  uint32 *d2,
	  uint32 *d3,
	  FILE *fp,
	  uint32 swap,
	  uint32 *chksum);
int32
s3read_intv_3d(void ****arr,
	       size_t e_sz,
	       uint32 s,
	       uint32 e,
	       uint32 *d1,
	       uint32 *d2,
	       uint32 *d3,
	       FILE *fp,
	       uint32 swap,
	       uint32 *chksum);

int32
s3write_3d(void ***arr,
	   size_t e_sz,
	   uint32 d1,
	   uint32 d2,
	   uint32 d3,
	   FILE *fp,
	   uint32 *chksum);

int32
s3read_2d(void ***arr,
	  size_t e_sz,
	  uint32 *d1,
	  uint32 *d2,
	  FILE *fp,
	  uint32 swap,
	  uint32 *chksum);

int32
s3write_2d(void **arr,
	   size_t e_sz,
	   uint32 d1,
	   uint32 d2,
	   FILE *fp,
	   uint32 *chksum);

int32
s3read_1d(void **arr,
	  size_t e_sz,
	  uint32 *d1,
	  FILE *fp,
	  uint32 swap,
	  uint32 *chksum);

int32
s3write_1d(void *arr,
	   size_t e_sz,
	   uint32 d1,
	   FILE *fp,
	   uint32 *chksum);

#ifdef __cplusplus
}
#endif
#endif /* S3IO_H */ 


/*
 * Log record.  Maintained by RCS.
 *
 * $Log$
 * Revision 1.4  2004/07/21  17:46:10  egouvea
 * Changed the license terms to make it the same as sphinx2 and sphinx3.
 * 
 * Revision 1.3  2001/04/05 20:02:30  awb
 * *** empty log message ***
 *
 * Revision 1.2  2000/09/29 22:35:12  awb
 * *** empty log message ***
 *
 * Revision 1.1  2000/09/24 21:38:30  awb
 * *** empty log message ***
 *
 * Revision 1.1  97/07/16  11:39:10  eht
 * Initial revision
 * 
 *
 */
