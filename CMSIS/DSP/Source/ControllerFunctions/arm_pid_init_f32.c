/* ----------------------------------------------------------------------    
* Copyright (C) 2010-2014 ARM Limited. All rights reserved.    
*    
* $Date:        19. March 2015
* $Revision: 	V.1.4.5
*    
* Project: 	    CMSIS DSP Library    
* Title:	    arm_pid_init_f32.c    
*    
* Description:	Floating-point PID Control initialization function    
*				   
*    
* Target Processor: Cortex-M4/Cortex-M3/Cortex-M0
*  
* Redistribution and use in source and binary forms, with or without 
* modification, are permitted provided that the following conditions
* are met:
*   - Redistributions of source code must retain the above copyright
*     notice, this list of conditions and the following disclaimer.
*   - Redistributions in binary form must reproduce the above copyright
*     notice, this list of conditions and the following disclaimer in
*     the documentation and/or other materials provided with the 
*     distribution.
*   - Neither the name of ARM LIMITED nor the names of its contributors
*     may be used to endorse or promote products derived from this
*     software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
* "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
* LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
* FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE 
* COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
* INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
* BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
* CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
* LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
* ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
* POSSIBILITY OF SUCH DAMAGE.   
* ------------------------------------------------------------------- */

#include "arm_math.h"

 /**    
 * @addtogroup PID    
 * @{    
 */

/**    
 * @brief  Initialization function for the floating-point PID Control.   
 * @param[in,out] *S points to an instance of the PID structure.   
 * @param[in]     resetStateFlag  flag to reset the state. 0 = no change in state & 1 = reset the state.   
 * @return none.   
 * \par Description:   
 * \par    
 * The <code>resetStateFlag</code> specifies whether to set state to zero or not. \n   
 * The function computes the structure fields: <code>A0</code>, <code>A1</code> <code>A2</code>    
 * using the proportional gain( \c Kp), integral gain( \c Ki) and derivative gain( \c Kd)    
 * also sets the state variables to all zeros.    
 */

void arm_pid_init_f32(
  arm_pid_instance_f32 * S,
  int32_t resetStateFlag)
{

  /* Derived coefficient A0 */
  S->A0 = S->Kp + S->Ki + S->Kd;

  /* Derived coefficient A1 */
  S->A1 = (-S->Kp) - ((float32_t) 2.0 * S->Kd);

  /* Derived coefficient A2 */
  S->A2 = S->Kd;

  /* Check whether state needs reset or not */
  if (resetStateFlag)
  {
    /* Clear the state buffer.  The size will be always 3 samples */
    memset(S->state, 0, 3u * sizeof(float32_t));
  }

}

/**    
 * @} end of PID group    
 */
