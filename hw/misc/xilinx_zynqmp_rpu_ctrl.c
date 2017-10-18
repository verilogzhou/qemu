/*
 * QEMU model of the RPU Realtime Processing Unit
 *
 * Copyright (c) 2014 Xilinx Inc.
 *
 * Autogenerated by xregqemu.py 2014-02-05.
 * Updated by Edgar E. Iglesias <edgar.iglesias@xilinx.com>
 * Updated by Peter Crosthwaite <peter.crosthwaite@xilinx.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include "qemu/osdep.h"
#include "hw/sysbus.h"
#include "hw/register.h"
#include "qemu/bitops.h"
#include "qapi/error.h"
#include "qemu/log.h"
#include "qapi/qmp/qerror.h"

#include "hw/fdt_generic_util.h"
#include "hw/intc/xlnx_scu_gic.h"

#ifndef XLNX_RPU_CTRL_ERR_DEBUG
#define XLNX_RPU_CTRL_ERR_DEBUG 0
#endif

#define TYPE_XLNX_RPU_CTRL "xlnx.rpu-control"

#define XLNX_RPU_CTRL(obj) \
     OBJECT_CHECK(XlnxZynqMPRPUCtrl, (obj), TYPE_XLNX_RPU_CTRL)

REG32(RPU_GLBL_CNTL, 0x0)
    FIELD(RPU_GLBL_CNTL, GIC_AXPROT, 10, 1)
    FIELD(RPU_GLBL_CNTL, TCM_CLK_CNTL, 8, 1)
    FIELD(RPU_GLBL_CNTL, TCM_WAIT, 7, 1)
    FIELD(RPU_GLBL_CNTL, TCM_COMB, 6, 1)
    FIELD(RPU_GLBL_CNTL, TEINIT, 5, 1)
    FIELD(RPU_GLBL_CNTL, SLCLAMP, 4, 1)
    FIELD(RPU_GLBL_CNTL, SLSPLIT, 3, 1)
    FIELD(RPU_GLBL_CNTL, DBGNOCLKSTOP, 2, 1)
    FIELD(RPU_GLBL_CNTL, CFGIE, 1, 1)
    FIELD(RPU_GLBL_CNTL, CFGEE, 0, 1)
REG32(RPU_GLBL_STATUS, 0x4)
    FIELD(RPU_GLBL_STATUS, DBGNOPWRDWN, 0, 1)
REG32(RPU_ERR_CNTL, 0x8)
    FIELD(RPU_ERR_CNTL, APB_ERR_RES, 0, 1)
REG32(RPU_RAM, 0xc)
    FIELD(RPU_RAM, RAMCONTROL1, 8, 8)
    FIELD(RPU_RAM, RAMCONTROL0, 0, 8)
REG32(RPU_ERR_INJ, 0x20)
    FIELD(RPU_ERR_INJ, DCCMINP2, 8, 8)
    FIELD(RPU_ERR_INJ, DCCMINP, 0, 8)
REG32(RPU_CCF_MASK, 0x24)
    FIELD(RPU_CCF_MASK, TEST_MBIST_MODE, 7, 1)
    FIELD(RPU_CCF_MASK, TEST_SCAN_MODE_LP, 6, 1)
    FIELD(RPU_CCF_MASK, TEST_SCAN_MODE, 5, 1)
    FIELD(RPU_CCF_MASK, ISO, 4, 1)
    FIELD(RPU_CCF_MASK, PGE, 3, 1)
    FIELD(RPU_CCF_MASK, R50_DBG_RST, 2, 1)
    FIELD(RPU_CCF_MASK, R50_RST, 1, 1)
    FIELD(RPU_CCF_MASK, PGE_RST, 0, 1)
REG32(RPU_INTR_0, 0x28)
REG32(RPU_INTR_1, 0x2c)
REG32(RPU_INTR_2, 0x30)
REG32(RPU_INTR_3, 0x34)
REG32(RPU_INTR_4, 0x38)
REG32(RPU_INTR_MASK_0, 0x40)
REG32(RPU_INTR_MASK_1, 0x44)
REG32(RPU_INTR_MASK_2, 0x48)
REG32(RPU_INTR_MASK_3, 0x4c)
REG32(RPU_INTR_MASK_4, 0x50)
REG32(RPU_CCF_VAL, 0x54)
    FIELD(RPU_CCF_VAL, TEST_MBIST_MODE, 7, 1)
    FIELD(RPU_CCF_VAL, TEST_SCAN_MODE_LP, 6, 1)
    FIELD(RPU_CCF_VAL, TEST_SCAN_MODE, 5, 1)
    FIELD(RPU_CCF_VAL, ISO, 4, 1)
    FIELD(RPU_CCF_VAL, PGE, 3, 1)
    FIELD(RPU_CCF_VAL, R50_DBG_RST, 2, 1)
    FIELD(RPU_CCF_VAL, R50_RST, 1, 1)
    FIELD(RPU_CCF_VAL, PGE_RST, 0, 1)
REG32(RPU_SAFETY_CHK, 0xf0)
REG32(RPU, 0xf4)
REG32(RPU_0_CFG, 0x100)
    FIELD(RPU_0_CFG, CFGNMFI0, 3, 1)
    FIELD(RPU_0_CFG, VINITHI, 2, 1)
    FIELD(RPU_0_CFG, COHERENT, 1, 1)
    FIELD(RPU_0_CFG, NCPUHALT, 0, 1)
REG32(RPU_0_STATUS, 0x104)
    FIELD(RPU_0_STATUS, NVALRESET, 5, 1)
    FIELD(RPU_0_STATUS, NVALIRQ, 4, 1)
    FIELD(RPU_0_STATUS, NVALFIQ, 3, 1)
    FIELD(RPU_0_STATUS, NWFIPIPESTOPPED, 2, 1)
    FIELD(RPU_0_STATUS, NWFEPIPESTOPPED, 1, 1)
    FIELD(RPU_0_STATUS, NCLKSTOPPED, 0, 1)
REG32(RPU_0_PWRDWN, 0x108)
    FIELD(RPU_0_PWRDWN, EN, 0, 1)
REG32(RPU_0_ISR, 0x114)
    FIELD(RPU_0_ISR, FPUFC, 24, 1)
    FIELD(RPU_0_ISR, FPOFC, 23, 1)
    FIELD(RPU_0_ISR, FPIXC, 22, 1)
    FIELD(RPU_0_ISR, FPIOC, 21, 1)
    FIELD(RPU_0_ISR, FPIDC, 20, 1)
    FIELD(RPU_0_ISR, FPDZC, 19, 1)
    FIELD(RPU_0_ISR, TCM_ASLV_CE, 18, 1)
    FIELD(RPU_0_ISR, TCM_ASLV_FAT, 17, 1)
    FIELD(RPU_0_ISR, TCM_LST_CE, 16, 1)
    FIELD(RPU_0_ISR, TCM_PREFETCH_CE, 15, 1)
    FIELD(RPU_0_ISR, B1TCM_CE, 14, 1)
    FIELD(RPU_0_ISR, B0TCM_CE, 13, 1)
    FIELD(RPU_0_ISR, ATCM_CE, 12, 1)
    FIELD(RPU_0_ISR, B1TCM_UE, 11, 1)
    FIELD(RPU_0_ISR, B0TCM_UE, 10, 1)
    FIELD(RPU_0_ISR, ATCM_UE, 9, 1)
    FIELD(RPU_0_ISR, DTAG_DIRTY_FAT, 8, 1)
    FIELD(RPU_0_ISR, DDATA_FAT, 7, 1)
    FIELD(RPU_0_ISR, TCM_LST_FAT, 6, 1)
    FIELD(RPU_0_ISR, TCM_PREFETCH_FAT, 5, 1)
    FIELD(RPU_0_ISR, DDATA_CE, 4, 1)
    FIELD(RPU_0_ISR, DTAG_DIRTY_CE, 3, 1)
    FIELD(RPU_0_ISR, IDATA_CE, 2, 1)
    FIELD(RPU_0_ISR, ITAG_CE, 1, 1)
    FIELD(RPU_0_ISR, APB_ERR, 0, 1)
REG32(RPU_0_IMR, 0x118)
    FIELD(RPU_0_IMR, FPUFC, 24, 1)
    FIELD(RPU_0_IMR, FPOFC, 23, 1)
    FIELD(RPU_0_IMR, FPIXC, 22, 1)
    FIELD(RPU_0_IMR, FPIOC, 21, 1)
    FIELD(RPU_0_IMR, FPIDC, 20, 1)
    FIELD(RPU_0_IMR, FPDZC, 19, 1)
    FIELD(RPU_0_IMR, TCM_ASLV_CE, 18, 1)
    FIELD(RPU_0_IMR, TCM_ASLV_FAT, 17, 1)
    FIELD(RPU_0_IMR, TCM_LST_CE, 16, 1)
    FIELD(RPU_0_IMR, TCM_PREFETCH_CE, 15, 1)
    FIELD(RPU_0_IMR, B1TCM_CE, 14, 1)
    FIELD(RPU_0_IMR, B0TCM_CE, 13, 1)
    FIELD(RPU_0_IMR, ATCM_CE, 12, 1)
    FIELD(RPU_0_IMR, B1TCM_UE, 11, 1)
    FIELD(RPU_0_IMR, B0TCM_UE, 10, 1)
    FIELD(RPU_0_IMR, ATCM_UE, 9, 1)
    FIELD(RPU_0_IMR, DTAG_DIRTY_FAT, 8, 1)
    FIELD(RPU_0_IMR, DDATA_FAT, 7, 1)
    FIELD(RPU_0_IMR, TCM_LST_FAT, 6, 1)
    FIELD(RPU_0_IMR, TCM_PREFETCH_FAT, 5, 1)
    FIELD(RPU_0_IMR, DDATA_CE, 4, 1)
    FIELD(RPU_0_IMR, DTAG_DIRTY_CE, 3, 1)
    FIELD(RPU_0_IMR, IDATA_CE, 2, 1)
    FIELD(RPU_0_IMR, ITAG_CE, 1, 1)
    FIELD(RPU_0_IMR, APB_ERR, 0, 1)
REG32(RPU_0_IEN, 0x11c)
    FIELD(RPU_0_IEN, FPUFC, 24, 1)
    FIELD(RPU_0_IEN, FPOFC, 23, 1)
    FIELD(RPU_0_IEN, FPIXC, 22, 1)
    FIELD(RPU_0_IEN, FPIOC, 21, 1)
    FIELD(RPU_0_IEN, FPIDC, 20, 1)
    FIELD(RPU_0_IEN, FPDZC, 19, 1)
    FIELD(RPU_0_IEN, TCM_ASLV_CE, 18, 1)
    FIELD(RPU_0_IEN, TCM_ASLV_FAT, 17, 1)
    FIELD(RPU_0_IEN, TCM_LST_CE, 16, 1)
    FIELD(RPU_0_IEN, TCM_PREFETCH_CE, 15, 1)
    FIELD(RPU_0_IEN, B1TCM_CE, 14, 1)
    FIELD(RPU_0_IEN, B0TCM_CE, 13, 1)
    FIELD(RPU_0_IEN, ATCM_CE, 12, 1)
    FIELD(RPU_0_IEN, B1TCM_UE, 11, 1)
    FIELD(RPU_0_IEN, B0TCM_UE, 10, 1)
    FIELD(RPU_0_IEN, ATCM_UE, 9, 1)
    FIELD(RPU_0_IEN, DTAG_DIRTY_FAT, 8, 1)
    FIELD(RPU_0_IEN, DDATA_FAT, 7, 1)
    FIELD(RPU_0_IEN, TCM_LST_FAT, 6, 1)
    FIELD(RPU_0_IEN, TCM_PREFETCH_FAT, 5, 1)
    FIELD(RPU_0_IEN, DDATA_CE, 4, 1)
    FIELD(RPU_0_IEN, DTAG_DIRTY_CE, 3, 1)
    FIELD(RPU_0_IEN, IDATA_CE, 2, 1)
    FIELD(RPU_0_IEN, ITAG_CE, 1, 1)
    FIELD(RPU_0_IEN, APB_ERR, 0, 1)
REG32(RPU_0_IDS, 0x120)
    FIELD(RPU_0_IDS, FPUFC, 24, 1)
    FIELD(RPU_0_IDS, FPOFC, 23, 1)
    FIELD(RPU_0_IDS, FPIXC, 22, 1)
    FIELD(RPU_0_IDS, FPIOC, 21, 1)
    FIELD(RPU_0_IDS, FPIDC, 20, 1)
    FIELD(RPU_0_IDS, FPDZC, 19, 1)
    FIELD(RPU_0_IDS, TCM_ASLV_CE, 18, 1)
    FIELD(RPU_0_IDS, TCM_ASLV_FAT, 17, 1)
    FIELD(RPU_0_IDS, TCM_LST_CE, 16, 1)
    FIELD(RPU_0_IDS, TCM_PREFETCH_CE, 15, 1)
    FIELD(RPU_0_IDS, B1TCM_CE, 14, 1)
    FIELD(RPU_0_IDS, B0TCM_CE, 13, 1)
    FIELD(RPU_0_IDS, ATCM_CE, 12, 1)
    FIELD(RPU_0_IDS, B1TCM_UE, 11, 1)
    FIELD(RPU_0_IDS, B0TCM_UE, 10, 1)
    FIELD(RPU_0_IDS, ATCM_UE, 9, 1)
    FIELD(RPU_0_IDS, DTAG_DIRTY_FAT, 8, 1)
    FIELD(RPU_0_IDS, DDATA_FAT, 7, 1)
    FIELD(RPU_0_IDS, TCM_LST_FAT, 6, 1)
    FIELD(RPU_0_IDS, TCM_PREFETCH_FAT, 5, 1)
    FIELD(RPU_0_IDS, DDATA_CE, 4, 1)
    FIELD(RPU_0_IDS, DTAG_DIRTY_CE, 3, 1)
    FIELD(RPU_0_IDS, IDATA_CE, 2, 1)
    FIELD(RPU_0_IDS, ITAG_CE, 1, 1)
    FIELD(RPU_0_IDS, APB_ERR, 0, 1)
REG32(RPU_0_SLV_BASE, 0x124)
    FIELD(RPU_0_SLV_BASE, ADDR, 0, 8)
REG32(RPU_0_AXI_OVER, 0x128)
    FIELD(RPU_0_AXI_OVER, AWCACHE, 6, 4)
    FIELD(RPU_0_AXI_OVER, ARCACHE, 2, 4)
    FIELD(RPU_0_AXI_OVER, AWCACHE_EN, 1, 1)
    FIELD(RPU_0_AXI_OVER, ARCACHE_EN, 0, 1)
REG32(RPU_1_CFG, 0x200)
    FIELD(RPU_1_CFG, CFGNMFI1, 3, 1)
    FIELD(RPU_1_CFG, VINITHI, 2, 1)
    FIELD(RPU_1_CFG, COHERENT, 1, 1)
    FIELD(RPU_1_CFG, NCPUHALT, 0, 1)
REG32(RPU_1_STATUS, 0x204)
    FIELD(RPU_1_STATUS, NVALRESET, 5, 1)
    FIELD(RPU_1_STATUS, NVALIRQ, 4, 1)
    FIELD(RPU_1_STATUS, NVALFIQ, 3, 1)
    FIELD(RPU_1_STATUS, NWFIPIPESTOPPED, 2, 1)
    FIELD(RPU_1_STATUS, NWFEPIPESTOPPED, 1, 1)
    FIELD(RPU_1_STATUS, NCLKSTOPPED, 0, 1)
REG32(RPU_1_PWRDWN, 0x208)
    FIELD(RPU_1_PWRDWN, EN, 0, 1)
REG32(RPU_1_ISR, 0x214)
    FIELD(RPU_1_ISR, FPUFC, 24, 1)
    FIELD(RPU_1_ISR, FPOFC, 23, 1)
    FIELD(RPU_1_ISR, FPIXC, 22, 1)
    FIELD(RPU_1_ISR, FPIOC, 21, 1)
    FIELD(RPU_1_ISR, FPIDC, 20, 1)
    FIELD(RPU_1_ISR, FPDZC, 19, 1)
    FIELD(RPU_1_ISR, TCM_ASLV_CE, 18, 1)
    FIELD(RPU_1_ISR, TCM_ASLV_FAT, 17, 1)
    FIELD(RPU_1_ISR, TCM_LST_CE, 16, 1)
    FIELD(RPU_1_ISR, TCM_PREFETCH_CE, 15, 1)
    FIELD(RPU_1_ISR, B1TCM_CE, 14, 1)
    FIELD(RPU_1_ISR, B0TCM_CE, 13, 1)
    FIELD(RPU_1_ISR, ATCM_CE, 12, 1)
    FIELD(RPU_1_ISR, B1TCM_UE, 11, 1)
    FIELD(RPU_1_ISR, B0TCM_UE, 10, 1)
    FIELD(RPU_1_ISR, ATCM_UE, 9, 1)
    FIELD(RPU_1_ISR, DTAG_DIRTY_FAT, 8, 1)
    FIELD(RPU_1_ISR, DDATA_FAT, 7, 1)
    FIELD(RPU_1_ISR, TCM_LST_FAT, 6, 1)
    FIELD(RPU_1_ISR, TCM_PREFETCH_FAT, 5, 1)
    FIELD(RPU_1_ISR, DDATA_CE, 4, 1)
    FIELD(RPU_1_ISR, DTAG_DIRTY_CE, 3, 1)
    FIELD(RPU_1_ISR, IDATA_CE, 2, 1)
    FIELD(RPU_1_ISR, ITAG_CE, 1, 1)
    FIELD(RPU_1_ISR, APB_ERR, 0, 1)
REG32(RPU_1_IMR, 0x218)
    FIELD(RPU_1_IMR, FPUFC, 24, 1)
    FIELD(RPU_1_IMR, FPOFC, 23, 1)
    FIELD(RPU_1_IMR, FPIXC, 22, 1)
    FIELD(RPU_1_IMR, FPIOC, 21, 1)
    FIELD(RPU_1_IMR, FPIDC, 20, 1)
    FIELD(RPU_1_IMR, FPDZC, 19, 1)
    FIELD(RPU_1_IMR, TCM_ASLV_CE, 18, 1)
    FIELD(RPU_1_IMR, TCM_ASLV_FAT, 17, 1)
    FIELD(RPU_1_IMR, TCM_LST_CE, 16, 1)
    FIELD(RPU_1_IMR, TCM_PREFETCH_CE, 15, 1)
    FIELD(RPU_1_IMR, B1TCM_CE, 14, 1)
    FIELD(RPU_1_IMR, B0TCM_CE, 13, 1)
    FIELD(RPU_1_IMR, ATCM_CE, 12, 1)
    FIELD(RPU_1_IMR, B1TCM_UE, 11, 1)
    FIELD(RPU_1_IMR, B0TCM_UE, 10, 1)
    FIELD(RPU_1_IMR, ATCM_UE, 9, 1)
    FIELD(RPU_1_IMR, DTAG_DIRTY_FAT, 8, 1)
    FIELD(RPU_1_IMR, DDATA_FAT, 7, 1)
    FIELD(RPU_1_IMR, TCM_LST_FAT, 6, 1)
    FIELD(RPU_1_IMR, TCM_PREFETCH_FAT, 5, 1)
    FIELD(RPU_1_IMR, DDATA_CE, 4, 1)
    FIELD(RPU_1_IMR, DTAG_DIRTY_CE, 3, 1)
    FIELD(RPU_1_IMR, IDATA_CE, 2, 1)
    FIELD(RPU_1_IMR, ITAG_CE, 1, 1)
    FIELD(RPU_1_IMR, APB_ERR, 0, 1)
REG32(RPU_1_IEN, 0x21c)
    FIELD(RPU_1_IEN, FPUFC, 24, 1)
    FIELD(RPU_1_IEN, FPOFC, 23, 1)
    FIELD(RPU_1_IEN, FPIXC, 22, 1)
    FIELD(RPU_1_IEN, FPIOC, 21, 1)
    FIELD(RPU_1_IEN, FPIDC, 20, 1)
    FIELD(RPU_1_IEN, FPDZC, 19, 1)
    FIELD(RPU_1_IEN, TCM_ASLV_CE, 18, 1)
    FIELD(RPU_1_IEN, TCM_ASLV_FAT, 17, 1)
    FIELD(RPU_1_IEN, TCM_LST_CE, 16, 1)
    FIELD(RPU_1_IEN, TCM_PREFETCH_CE, 15, 1)
    FIELD(RPU_1_IEN, B1TCM_CE, 14, 1)
    FIELD(RPU_1_IEN, B0TCM_CE, 13, 1)
    FIELD(RPU_1_IEN, ATCM_CE, 12, 1)
    FIELD(RPU_1_IEN, B1TCM_UE, 11, 1)
    FIELD(RPU_1_IEN, B0TCM_UE, 10, 1)
    FIELD(RPU_1_IEN, ATCM_UE, 9, 1)
    FIELD(RPU_1_IEN, DTAG_DIRTY_FAT, 8, 1)
    FIELD(RPU_1_IEN, DDATA_FAT, 7, 1)
    FIELD(RPU_1_IEN, TCM_LST_FAT, 6, 1)
    FIELD(RPU_1_IEN, TCM_PREFETCH_FAT, 5, 1)
    FIELD(RPU_1_IEN, DDATA_CE, 4, 1)
    FIELD(RPU_1_IEN, DTAG_DIRTY_CE, 3, 1)
    FIELD(RPU_1_IEN, IDATA_CE, 2, 1)
    FIELD(RPU_1_IEN, ITAG_CE, 1, 1)
    FIELD(RPU_1_IEN, APB_ERR, 0, 1)
REG32(RPU_1_IDS, 0x220)
    FIELD(RPU_1_IDS, FPUFC, 24, 1)
    FIELD(RPU_1_IDS, FPOFC, 23, 1)
    FIELD(RPU_1_IDS, FPIXC, 22, 1)
    FIELD(RPU_1_IDS, FPIOC, 21, 1)
    FIELD(RPU_1_IDS, FPIDC, 20, 1)
    FIELD(RPU_1_IDS, FPDZC, 19, 1)
    FIELD(RPU_1_IDS, TCM_ASLV_CE, 18, 1)
    FIELD(RPU_1_IDS, TCM_ASLV_FAT, 17, 1)
    FIELD(RPU_1_IDS, TCM_LST_CE, 16, 1)
    FIELD(RPU_1_IDS, TCM_PREFETCH_CE, 15, 1)
    FIELD(RPU_1_IDS, B1TCM_CE, 14, 1)
    FIELD(RPU_1_IDS, B0TCM_CE, 13, 1)
    FIELD(RPU_1_IDS, ATCM_CE, 12, 1)
    FIELD(RPU_1_IDS, B1TCM_UE, 11, 1)
    FIELD(RPU_1_IDS, B0TCM_UE, 10, 1)
    FIELD(RPU_1_IDS, ATCM_UE, 9, 1)
    FIELD(RPU_1_IDS, DTAG_DIRTY_FAT, 8, 1)
    FIELD(RPU_1_IDS, DDATA_FAT, 7, 1)
    FIELD(RPU_1_IDS, TCM_LST_FAT, 6, 1)
    FIELD(RPU_1_IDS, TCM_PREFETCH_FAT, 5, 1)
    FIELD(RPU_1_IDS, DDATA_CE, 4, 1)
    FIELD(RPU_1_IDS, DTAG_DIRTY_CE, 3, 1)
    FIELD(RPU_1_IDS, IDATA_CE, 2, 1)
    FIELD(RPU_1_IDS, ITAG_CE, 1, 1)
    FIELD(RPU_1_IDS, APB_ERR, 0, 1)
REG32(RPU_1_SLV_BASE, 0x224)
    FIELD(RPU_1_SLV_BASE, ADDR, 0, 8)
REG32(RPU_1_AXI_OVER, 0x228)
    FIELD(RPU_1_AXI_OVER, AWCACHE, 6, 4)
    FIELD(RPU_1_AXI_OVER, ARCACHE, 2, 4)
    FIELD(RPU_1_AXI_OVER, AWCACHE_EN, 1, 1)
    FIELD(RPU_1_AXI_OVER, ARCACHE_EN, 0, 1)

#define RPU_CTRL_R_MAX (R_RPU_1_AXI_OVER + 1)

#define NUM_CONT_OUT_IRQS    7

enum cont_out_array_nums {
    R5_0_HALT = 0,
    R5_1_HALT,
    R5_SLSPLIT,
    R5_0_PWRDWN_REQ,
    R5_1_PWRDWN_REQ,
    R5_0_VINITHI,
    R5_1_VINITHI = 6
};

static const char *cont_out_array_names[NUM_CONT_OUT_IRQS] = {
                                        "R5_0_HALT", "R5_1_HALT",
                                        "R5_SLSPLIT",
                                        "R5_0_PWRDWN_REQ", "R5_1_PWRDWN_REQ",
                                        "R5_0_VINITHI", "R5_1_VINITHI"
                                                             };

/* Returns the interrupt bank from the register offset. */
#define INT_INJ_BANK_FROM_OFFSET(n) (((n) <= R_RPU_INTR_4)                     \
                                     ? ((n) - R_RPU_INTR_0)                    \
                                     : ((n) - R_RPU_INTR_MASK_0))
#define R_RPU_INTR(n) (n + R_RPU_INTR_0)
#define R_RPU_INTR_MASK(n) (n + R_RPU_INTR_MASK_0)

typedef struct XlnxZynqMPRPUCtrl {
    SysBusDevice parent_obj;
    MemoryRegion iomem;
    qemu_irq irq_rpu_1;
    qemu_irq irq_rpu_0;

    MemoryRegion *atcm1_for_rpu0;
    MemoryRegion *btcm1_for_rpu0;
    MemoryRegion atcm1_mask;
    MemoryRegion btcm1_mask;
    MemoryRegion *rpu1_for_main_bus;
    /* MemoryRegion for the rpu1 caches. */
    MemoryRegion *icache_for_rpu1;
    MemoryRegion *dcache_for_rpu1;
    /* Second part of the DDR. */
    MemoryRegion *ddr;

    /* GIC associated to the RPUs. */
    XlnxSCUGICState *gic;

    /* WFIs towards PMU. */
    qemu_irq wfi_out[2];
    /* Comparators fault. */
    qemu_irq comp_fault[2];
    /* General outbound GPIO lines */
    qemu_irq cont_out_gpios[NUM_CONT_OUT_IRQS];

    bool cpu_in_wfi[2];

    uint32_t regs[RPU_CTRL_R_MAX];
    RegisterInfo regs_info[RPU_CTRL_R_MAX];
} XlnxZynqMPRPUCtrl;

static void rpu_1_update_irq(XlnxZynqMPRPUCtrl *s)
{
    bool pending = s->regs[R_RPU_1_ISR] & ~s->regs[R_RPU_1_IMR];
    qemu_set_irq(s->irq_rpu_1, pending);
}

static void ronaldo_rpu_err_inj(RegisterInfo *reg, uint64_t val64)
{
    XlnxZynqMPRPUCtrl *s = XLNX_RPU_CTRL(reg->opaque);
    bool comp_0 = ARRAY_FIELD_EX32(s->regs, RPU_ERR_INJ, DCCMINP);
    bool comp_1 = ARRAY_FIELD_EX32(s->regs, RPU_ERR_INJ, DCCMINP2);

    /* Inject an error in the comparator
     * Works even if the CLAMP bit is cleared.
     */
    qemu_set_irq(s->comp_fault[0], comp_0);
    qemu_set_irq(s->comp_fault[1], comp_1);
}

static void rpu_1_isr_postw(RegisterInfo *reg, uint64_t val64)
{
    XlnxZynqMPRPUCtrl *s = XLNX_RPU_CTRL(reg->opaque);
    rpu_1_update_irq(s);
}

static void ronaldo_rpu_update_irq_injection(RegisterInfo *reg, uint64_t val)
{
    XlnxZynqMPRPUCtrl *s = XLNX_RPU_CTRL(reg->opaque);

    uint8_t bank = INT_INJ_BANK_FROM_OFFSET(reg->access->addr >> 2);
    uint32_t irqs = s->regs[R_RPU_INTR(bank)] &
                    s->regs[R_RPU_INTR_MASK(bank)];

    xlnx_scu_gic_set_intr(s->gic, bank, irqs, 0);
}

static uint64_t rpu_1_ien_prew(RegisterInfo *reg, uint64_t val64)
{
    XlnxZynqMPRPUCtrl *s = XLNX_RPU_CTRL(reg->opaque);
    uint32_t val = val64;

    s->regs[R_RPU_1_IMR] &= ~val;
    rpu_1_update_irq(s);
    return 0;
}

static uint64_t rpu_1_ids_prew(RegisterInfo *reg, uint64_t val64)
{
    XlnxZynqMPRPUCtrl *s = XLNX_RPU_CTRL(reg->opaque);
    uint32_t val = val64;

    s->regs[R_RPU_1_IMR] |= val;
    rpu_1_update_irq(s);
    return 0;
}

static void rpu_0_update_irq(XlnxZynqMPRPUCtrl *s)
{
    bool pending = s->regs[R_RPU_0_ISR] & ~s->regs[R_RPU_0_IMR];
    qemu_set_irq(s->irq_rpu_0, pending);
}

static void rpu_0_isr_postw(RegisterInfo *reg, uint64_t val64)
{
    XlnxZynqMPRPUCtrl *s = XLNX_RPU_CTRL(reg->opaque);
    rpu_0_update_irq(s);
}

static uint64_t rpu_0_ien_prew(RegisterInfo *reg, uint64_t val64)
{
    XlnxZynqMPRPUCtrl *s = XLNX_RPU_CTRL(reg->opaque);
    uint32_t val = val64;

    s->regs[R_RPU_0_IMR] &= ~val;
    rpu_0_update_irq(s);
    return 0;
}

static uint64_t rpu_0_ids_prew(RegisterInfo *reg, uint64_t val64)
{
    XlnxZynqMPRPUCtrl *s = XLNX_RPU_CTRL(reg->opaque);
    uint32_t val = val64;

    s->regs[R_RPU_0_IMR] |= val;
    rpu_0_update_irq(s);
    return 0;
}

static void rpu_rpu_glbl_cntl_postw(RegisterInfo *reg, uint64_t val64)
{
    XlnxZynqMPRPUCtrl *s = XLNX_RPU_CTRL(reg->opaque);
    bool tcm_comb = ARRAY_FIELD_EX32(s->regs, RPU_GLBL_CNTL, TCM_COMB);
    bool sls_split = ARRAY_FIELD_EX32(s->regs, RPU_GLBL_CNTL, SLSPLIT);

    memory_region_set_enabled(&s->atcm1_mask, !tcm_comb);
    memory_region_set_enabled(&s->btcm1_mask, !tcm_comb);

    memory_region_set_enabled(s->icache_for_rpu1, sls_split);
    memory_region_set_enabled(s->dcache_for_rpu1, sls_split);
    memory_region_set_enabled(s->ddr, sls_split);

    /* Inverse polarity */
    qemu_set_irq(s->cont_out_gpios[R5_SLSPLIT],
                 !(val64 & R_RPU_GLBL_CNTL_SLSPLIT_MASK));
}

static void update_wfi_out(void *opaque)
{
    XlnxZynqMPRPUCtrl *s = XLNX_RPU_CTRL(opaque);
    unsigned int i, wfi_pending;
    unsigned int pwrdnreq[2];

    pwrdnreq[0] = ARRAY_FIELD_EX32(s->regs, RPU_0_PWRDWN, EN);
    pwrdnreq[1] = ARRAY_FIELD_EX32(s->regs, RPU_1_PWRDWN, EN);

    for (i = 0; i < 2; i++) {
        wfi_pending = pwrdnreq[i] && s->cpu_in_wfi[i];
        qemu_set_irq(s->wfi_out[i], wfi_pending);
    }
}

static void zynqmp_rpu_pwrctl_post_write(RegisterInfo *reg, uint64_t val)
{
    XlnxZynqMPRPUCtrl *s = XLNX_RPU_CTRL(reg->opaque);

    if (reg->access->addr == A_RPU_0_PWRDWN) {
        qemu_set_irq(s->cont_out_gpios[R5_0_PWRDWN_REQ],
                     !!(val & R_RPU_0_PWRDWN_EN_MASK));
    } else if (reg->access->addr == A_RPU_1_PWRDWN) {
        qemu_set_irq(s->cont_out_gpios[R5_1_PWRDWN_REQ],
                     !!(val & R_RPU_1_PWRDWN_EN_MASK));
    } else {
        g_assert_not_reached();
    }

    update_wfi_out(s);
}

static void zynqmp_rpu_cfg_post_write(RegisterInfo *reg, uint64_t val)
{
    XlnxZynqMPRPUCtrl *s = XLNX_RPU_CTRL(reg->opaque);

    if (reg->access->addr == A_RPU_0_CFG) {
        /* Inverse polarity */
        qemu_set_irq(s->cont_out_gpios[R5_0_HALT],
                     !(val & R_RPU_0_CFG_NCPUHALT_MASK));

        qemu_set_irq(s->cont_out_gpios[R5_0_VINITHI],
                     !!(val & R_RPU_0_CFG_VINITHI_MASK));
    } else if (reg->access->addr == A_RPU_1_CFG) {
        /* Inverse polarity*/
        qemu_set_irq(s->cont_out_gpios[R5_1_HALT],
                     !(val & R_RPU_1_CFG_NCPUHALT_MASK));

        qemu_set_irq(s->cont_out_gpios[R5_1_VINITHI],
                     !!(val & R_RPU_1_CFG_VINITHI_MASK));
    } else {
        g_assert_not_reached();
    }
}

static uint64_t rpu_1_cfg_pw(RegisterInfo *reg, uint64_t val)
{
    XlnxZynqMPRPUCtrl *s = XLNX_RPU_CTRL(reg->opaque);

    /* Split-Mode: Remove R5-1 from hold upon request
     * LockStep-Mode: Keep R5-1 under hold, to make only R5-0 run
     *                in Lockstep.
     */
    if (!ARRAY_FIELD_EX32(s->regs, RPU_GLBL_CNTL, SLSPLIT)) {
        /* Lock-Step Mode, Clear the hold bit to keep the
         *  core in HOLD state.
         */
        val &= ~(R_RPU_1_CFG_NCPUHALT_MASK);
    }
    return val;
}

static const RegisterAccessInfo rpu_regs_info[] = {
    {   .name = "RPU_GLBL_CNTL",  .addr = A_RPU_GLBL_CNTL,
        .reset = 0x50,
        .rsvd = 0xfffffa00,
        .post_write = rpu_rpu_glbl_cntl_postw,
    },{ .name = "RPU_GLBL_STATUS",  .addr = A_RPU_GLBL_STATUS,
        .rsvd = 0xfffffffe,
        .ro = 0x1,
    },{ .name = "RPU_ERR_CNTL",  .addr = A_RPU_ERR_CNTL,
        .rsvd = 0xfffffffe,
    },{ .name = "RPU_RAM",  .addr = A_RPU_RAM,
        .rsvd = 0xffff0000,
    },{ .name = "RPU_ERR_INJ",  .addr = A_RPU_ERR_INJ,
        .rsvd = 0xffff0000,
        .post_write = ronaldo_rpu_err_inj,
    },{ .name = "RPU_CCF_MASK",  .addr = A_RPU_CCF_MASK,
        .rsvd = 0xffffff00,
    },{ .name = "RPU_INTR_0",  .addr = A_RPU_INTR_0,
        .post_write = ronaldo_rpu_update_irq_injection,
    },{ .name = "RPU_INTR_1",  .addr = A_RPU_INTR_1,
        .post_write = ronaldo_rpu_update_irq_injection,
    },{ .name = "RPU_INTR_2",  .addr = A_RPU_INTR_2,
        .post_write = ronaldo_rpu_update_irq_injection,
    },{ .name = "RPU_INTR_3",  .addr = A_RPU_INTR_3,
        .post_write = ronaldo_rpu_update_irq_injection,
    },{ .name = "RPU_INTR_4",  .addr = A_RPU_INTR_4,
        .post_write = ronaldo_rpu_update_irq_injection,
    },{ .name = "RPU_INTR_MASK_0",  .addr = A_RPU_INTR_MASK_0,
        .post_write = ronaldo_rpu_update_irq_injection,
    },{ .name = "RPU_INTR_MASK_1",  .addr = A_RPU_INTR_MASK_1,
        .post_write = ronaldo_rpu_update_irq_injection,
    },{ .name = "RPU_INTR_MASK_2",  .addr = A_RPU_INTR_MASK_2,
        .post_write = ronaldo_rpu_update_irq_injection,
    },{ .name = "RPU_INTR_MASK_3",  .addr = A_RPU_INTR_MASK_3,
        .post_write = ronaldo_rpu_update_irq_injection,
    },{ .name = "RPU_INTR_MASK_4",  .addr = A_RPU_INTR_MASK_4,
        .post_write = ronaldo_rpu_update_irq_injection,
    },{ .name = "RPU_CCF_VAL",  .addr = A_RPU_CCF_VAL,
        .reset = 0x7,
        .rsvd = 0xffffff00,
    },{ .name = "RPU_SAFETY_CHK",  .addr = A_RPU_SAFETY_CHK,
    },{ .name = "RPU",  .addr = A_RPU,
    },{ .name = "RPU_0_CFG",  .addr = A_RPU_0_CFG,
        .reset = 0x5,
        .rsvd = 0xfffffff0,
        .post_write = zynqmp_rpu_cfg_post_write,
    },{ .name = "RPU_0_STATUS",  .addr = A_RPU_0_STATUS,
        .reset = 0x3f,
        .rsvd = 0xffffffc0,
        .ro = 0x3f,
    },{ .name = "RPU_0_PWRDWN",  .addr = A_RPU_0_PWRDWN,
        .rsvd = 0xfffffffe,
        .post_write = zynqmp_rpu_pwrctl_post_write,
    },{ .name = "RPU_0_ISR",  .addr = A_RPU_0_ISR,
        .rsvd = 0xfe000000,
        .w1c = 0x1ffffff,
        .post_write = rpu_0_isr_postw,
    },{ .name = "RPU_0_IMR",  .addr = A_RPU_0_IMR,
        .reset = 0x1ffffff,
        .rsvd = 0xfe000000,
        .ro = 0x1ffffff,
    },{ .name = "RPU_0_IEN",  .addr = A_RPU_0_IEN,
        .rsvd = 0xfe000000,
        .pre_write = rpu_0_ien_prew,
    },{ .name = "RPU_0_IDS",  .addr = A_RPU_0_IDS,
        .rsvd = 0xfe000000,
        .pre_write = rpu_0_ids_prew,
    },{ .name = "RPU_0_SLV_BASE",  .addr = A_RPU_0_SLV_BASE,
        .rsvd = 0xffffff00,
    },{ .name = "RPU_0_AXI_OVER",  .addr = A_RPU_0_AXI_OVER,
        .rsvd = 0xfffffc00,
    },{ .name = "RPU_1_CFG",  .addr = A_RPU_1_CFG,
        .reset = 0x5,
        .rsvd = 0xfffffff0,
        .pre_write = rpu_1_cfg_pw,
        .post_write = zynqmp_rpu_cfg_post_write,
    },{ .name = "RPU_1_STATUS",  .addr = A_RPU_1_STATUS,
        .reset = 0x3f,
        .rsvd = 0xffffffc0,
        .ro = 0x3f,
    },{ .name = "RPU_1_PWRDWN",  .addr = A_RPU_1_PWRDWN,
        .rsvd = 0xfffffffe,
        .post_write = zynqmp_rpu_pwrctl_post_write,
    },{ .name = "RPU_1_ISR",  .addr = A_RPU_1_ISR,
        .rsvd = 0xfe000000,
        .w1c = 0x1ffffff,
        .post_write = rpu_1_isr_postw,
    },{ .name = "RPU_1_IMR",  .addr = A_RPU_1_IMR,
        .reset = 0x1ffffff,
        .rsvd = 0xfe000000,
        .ro = 0x1ffffff,
    },{ .name = "RPU_1_IEN",  .addr = A_RPU_1_IEN,
        .rsvd = 0xfe000000,
        .pre_write = rpu_1_ien_prew,
    },{ .name = "RPU_1_IDS",  .addr = A_RPU_1_IDS,
        .rsvd = 0xfe000000,
        .pre_write = rpu_1_ids_prew,
    },{ .name = "RPU_1_SLV_BASE",  .addr = A_RPU_1_SLV_BASE,
        .rsvd = 0xffffff00,
    },{ .name = "RPU_1_AXI_OVER",  .addr = A_RPU_1_AXI_OVER,
        .rsvd = 0xfffffc00,
    }
};

static void rpu_reset(DeviceState *dev)
{
    XlnxZynqMPRPUCtrl *s = XLNX_RPU_CTRL(dev);
    unsigned int i;

    for (i = 0; i < ARRAY_SIZE(s->regs_info); ++i) {
        register_reset(&s->regs_info[i]);
    }

    rpu_1_update_irq(s);
    rpu_0_update_irq(s);

    for (i = 0; i < 2; i++) {
        s->cpu_in_wfi[i] = false;
    }
    update_wfi_out(s);
}

static const MemoryRegionOps rpu_ops = {
    .read = register_read_memory,
    .write = register_write_memory,
    .endianness = DEVICE_LITTLE_ENDIAN,
    .valid = {
        .min_access_size = 4,
        .max_access_size = 4,
    },
};

static uint64_t disabled_tcm_read(void *opaque, hwaddr addr, unsigned size)
{
    Object *obj = OBJECT(opaque);

    qemu_log_mask(LOG_GUEST_ERROR, "%s: Read to unmapped TCM while RPU is in"
                  " lockstep mode @%" HWADDR_PRIx "\n",
                  object_get_canonical_path(obj), addr);
    return 0;
}

static void disabled_tcm_write(void *opaque, hwaddr addr, uint64_t value,
                               unsigned size)
{
    Object *obj = OBJECT(opaque);

    qemu_log_mask(LOG_GUEST_ERROR, "%s: Write to unmapped TCM while RPU is in"
                  " lockstep mode @%" HWADDR_PRIx "\n",
                  object_get_canonical_path(obj), addr);
}

static const MemoryRegionOps disabled_tcm_ops = {
    .read = disabled_tcm_read,
    .write = disabled_tcm_write,
};

static void zynqmp_rpu_0_handle_wfi(void *opaque, int irq, int level)
{
    XlnxZynqMPRPUCtrl *s = XLNX_RPU_CTRL(opaque);

    s->cpu_in_wfi[0] = level;
    update_wfi_out(s);
}

static void zynqmp_rpu_1_handle_wfi(void *opaque, int irq, int level)
{
    XlnxZynqMPRPUCtrl *s = XLNX_RPU_CTRL(opaque);

    s->cpu_in_wfi[1] = level;
    update_wfi_out(s);
}

static void rpu_realize(DeviceState *dev, Error **errp)
{
    XlnxZynqMPRPUCtrl *s = XLNX_RPU_CTRL(dev);
    hwaddr region_addr;
    MemoryRegion *region_container;
    uint32_t region_priority;

    if (!s->atcm1_for_rpu0) {
        error_setg(errp, "atcm1-for-rpu0");
        return;
    }

    if (!s->btcm1_for_rpu0) {
        error_setg(errp, "btcm1-for-rpu0");
        return;
    }

    if (!s->icache_for_rpu1) {
        error_setg(errp, "icache-for-rpu1");
        return;
    }

    if (!s->dcache_for_rpu1) {
        error_setg(errp, "dcache-for-rpu1");
        return;
    }

    if (!s->ddr) {
        error_setg(errp, "ddr-mem-for-rpu");
        return;
    }

    if (!s->gic) {
        error_setg(errp, "gic-for-rpu");
        return;
    }

    /* RPUs starts in lockstep mode, so the rpu1 caches are not accessible. */
    memory_region_set_enabled(s->icache_for_rpu1, false);
    memory_region_set_enabled(s->dcache_for_rpu1, false);
    memory_region_set_enabled(s->ddr, false);

    /* This initialize some "mask" memory region
     * Basically they hide what is behind so the *tcm are not accessible.
     */
    memory_region_init_io(&s->atcm1_mask, OBJECT(s), &disabled_tcm_ops, s,
                          "atcm1_mask", memory_region_size(s->atcm1_for_rpu0));
    region_container = MEMORY_REGION(object_property_get_link(
                                                OBJECT(s->atcm1_for_rpu0),
                                                "container", NULL));
    region_addr = object_property_get_int(OBJECT(s->atcm1_for_rpu0), "addr",
                                          NULL);
    region_priority = object_property_get_int(OBJECT(s->atcm1_for_rpu0),
                                              "priority", NULL) + 1;
    object_property_set_int(OBJECT(&s->atcm1_mask), region_priority, "priority",
                            NULL);
    memory_region_add_subregion(region_container, region_addr, &s->atcm1_mask);

    memory_region_init_io(&s->btcm1_mask, OBJECT(s), &disabled_tcm_ops, s,
                          "btcm1_mask", memory_region_size(s->btcm1_for_rpu0));
    region_container = MEMORY_REGION(object_property_get_link(
                                                OBJECT(s->btcm1_for_rpu0),
                                                "container", NULL));
    region_addr = object_property_get_int(OBJECT(s->btcm1_for_rpu0), "addr",
                                          NULL);
    region_priority = object_property_get_int(OBJECT(s->btcm1_for_rpu0),
                                              "priority", NULL) + 1;
    object_property_set_int(OBJECT(&s->btcm1_mask), region_priority, "priority",
                            NULL);
    memory_region_add_subregion(region_container, region_addr, &s->btcm1_mask);
}

static void rpu_init(Object *obj)
{
    XlnxZynqMPRPUCtrl *s = XLNX_RPU_CTRL(obj);
    SysBusDevice *sbd = SYS_BUS_DEVICE(obj);
    RegisterInfoArray *reg_array;
    int i;

    memory_region_init(&s->iomem, obj, TYPE_XLNX_RPU_CTRL, RPU_CTRL_R_MAX * 4);
    reg_array =
        register_init_block32(DEVICE(obj), rpu_regs_info,
                              ARRAY_SIZE(rpu_regs_info),
                              s->regs_info, s->regs,
                              &rpu_ops,
                              XLNX_RPU_CTRL_ERR_DEBUG,
                              RPU_CTRL_R_MAX * 4);
    memory_region_add_subregion(&s->iomem,
                                0x0,
                                &reg_array->mem);
    sysbus_init_mmio(sbd, &s->iomem);
    sysbus_init_irq(sbd, &s->irq_rpu_1);
    sysbus_init_irq(sbd, &s->irq_rpu_0);

    /* xtcm1-for-rpu0 are the aliases for the tcm in lockstep mode.
     * This link allows to enable/disable those aliases when we are in
     * lock-step/normal mode.
     */
    object_property_add_link(obj, "atcm1-for-rpu0", TYPE_MEMORY_REGION,
                             (Object **)&s->atcm1_for_rpu0,
                             qdev_prop_allow_set_link_before_realize,
                             OBJ_PROP_LINK_UNREF_ON_RELEASE,
                             &error_abort);
    object_property_add_link(obj, "btcm1-for-rpu0", TYPE_MEMORY_REGION,
                             (Object **)&s->btcm1_for_rpu0,
                             qdev_prop_allow_set_link_before_realize,
                             OBJ_PROP_LINK_UNREF_ON_RELEASE,
                             &error_abort);
    object_property_add_link(obj, "rpu1-for-main-bus", TYPE_MEMORY_REGION,
                             (Object **)&s->atcm1_for_rpu0,
                             qdev_prop_allow_set_link_before_realize,
                             OBJ_PROP_LINK_UNREF_ON_RELEASE,
                             &error_abort);

    /* This link allows to enable/disable those memory region when we are in
     * lock-step/normal mode.
     */
    object_property_add_link(obj, "icache-for-rpu1", TYPE_MEMORY_REGION,
                             (Object **)&s->icache_for_rpu1,
                             qdev_prop_allow_set_link_before_realize,
                             OBJ_PROP_LINK_UNREF_ON_RELEASE,
                             &error_abort);
    object_property_add_link(obj, "dcache-for-rpu1", TYPE_MEMORY_REGION,
                             (Object **)&s->dcache_for_rpu1,
                             qdev_prop_allow_set_link_before_realize,
                             OBJ_PROP_LINK_UNREF_ON_RELEASE,
                             &error_abort);

    /* Link to the second part of the DDR which is enabled in split mode and
     * disabled in lockstep mode.
     */
    object_property_add_link(obj, "ddr-mem-for-rpu", TYPE_MEMORY_REGION,
                             (Object **)&s->ddr,
                             qdev_prop_allow_set_link_before_realize,
                             OBJ_PROP_LINK_UNREF_ON_RELEASE,
                             &error_abort);

    /* Link to the GIC which allow to inject irq through rpu_intr/rpu_mask
     * registers
     */
    object_property_add_link(obj, "gic-for-rpu", TYPE_XLNX_SCU_GIC,
                             (Object **)&s->gic,
                             qdev_prop_allow_set_link_before_realize,
                             OBJ_PROP_LINK_UNREF_ON_RELEASE,
                             &error_abort);

    /* comp_fault gpios are connected to the PMU. */
    qdev_init_gpio_out_named(DEVICE(obj), s->comp_fault, "comp_fault", 2);
    /* wfi_out is used to connect to PMU GPIs. */
    qdev_init_gpio_out_named(DEVICE(obj), s->wfi_out, "wfi_out", 2);

    for (i = 0; i < NUM_CONT_OUT_IRQS; i++) {
        qdev_init_gpio_out_named(DEVICE(obj), &s->cont_out_gpios[i],
                                 cont_out_array_names[i], 1);
    }

    /* wfi_in is used as input from CPUs as wfi request. */
    qdev_init_gpio_in_named(DEVICE(obj), zynqmp_rpu_0_handle_wfi, "wfi_in_0", 1);
    qdev_init_gpio_in_named(DEVICE(obj), zynqmp_rpu_1_handle_wfi, "wfi_in_1", 1);
}

static const VMStateDescription vmstate_rpu = {
    .name = TYPE_XLNX_RPU_CTRL,
    .version_id = 1,
    .minimum_version_id = 1,
    .minimum_version_id_old = 1,
    .fields = (VMStateField[]) {
        VMSTATE_UINT32_ARRAY(regs, XlnxZynqMPRPUCtrl, RPU_CTRL_R_MAX),
        VMSTATE_END_OF_LIST(),
    }
};

static const FDTGenericGPIOSet rpu_controller_gpios [] = {
    {
        .names = &fdt_generic_gpio_name_set_gpio,
        .gpios = (FDTGenericGPIOConnection [])  {
            { .name = "R5_0_HALT",          .fdt_index = R5_0_HALT },
            { .name = "R5_1_HALT",          .fdt_index = R5_1_HALT },
            { .name = "R5_SLSPLIT",         .fdt_index = R5_SLSPLIT },
            { .name = "R5_0_PWRDWN_REQ",    .fdt_index = R5_0_PWRDWN_REQ },
            { .name = "R5_1_PWRDWN_REQ",    .fdt_index = R5_1_PWRDWN_REQ },
            { .name = "R5_0_VINITHI",       .fdt_index = R5_0_VINITHI },
            { .name = "R5_1_VINITHI",       .fdt_index = R5_1_VINITHI },
            { .name = "wfi_in_0",           .fdt_index = 7 },
            { .name = "wfi_in_1",           .fdt_index = 8 },
            { },
        },
    },
    { },
};

static const FDTGenericGPIOSet rpu_client_gpios [] = {
    {
        .names = &fdt_generic_gpio_name_set_gpio,
        .gpios = (FDTGenericGPIOConnection [])  {
            { .name = "comp_fault",         .fdt_index = 0, .range = 2 },
            { .name = "wfi_out",            .fdt_index = 2, .range = 2 },
            { },
        },
    },
    { },
};

static void rpu_class_init(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);
    FDTGenericGPIOClass *fggc = FDT_GENERIC_GPIO_CLASS(klass);

    dc->reset = rpu_reset;
    dc->realize = rpu_realize;
    dc->vmsd = &vmstate_rpu;
    fggc->controller_gpios = rpu_controller_gpios;
    fggc->client_gpios = rpu_client_gpios;
}

static const TypeInfo rpu_info = {
    .name          = TYPE_XLNX_RPU_CTRL,
    .parent        = TYPE_SYS_BUS_DEVICE,
    .instance_size = sizeof(XlnxZynqMPRPUCtrl),
    .class_init    = rpu_class_init,
    .instance_init = rpu_init,
    .interfaces    = (InterfaceInfo[]) {
        { TYPE_FDT_GENERIC_GPIO },
        { }
    },
};

static void rpu_register_types(void)
{
    type_register_static(&rpu_info);
}

type_init(rpu_register_types)
