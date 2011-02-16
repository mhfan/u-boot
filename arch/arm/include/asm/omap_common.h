/*
 * (C) Copyright 2010
 * Texas Instruments, <www.ti.com>
 *
 * Aneesh V <aneesh@ti.com>
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */
#ifndef	_OMAP_COMMON_H_
#define	_OMAP_COMMON_H_

/* Max value for DPLL multiplier M */
#define OMAP_DPLL_MAX_N	127

/* extract a bit field from a bit vector */
#define get_bit_field(nr, start, mask)\
	(((nr) & (mask)) >> (start))

/* Set a field in a bit vector */
#define set_bit_field(nr, start, mask, val)\
	do { \
		(nr) = ((nr) & ~(mask)) | (((val) << (start)) & (mask));\
	} while (0);

/*
 * Utility macro for read-modify-write of a hardware register
 *	addr - address of the register
 *	shift - starting bit position of the field to be modified
 *	msk - mask for the field
 *	val - value to be shifted masked and written to the field
 */
#define modify_reg_32(addr, shift, msk, val) \
	do {\
		writel(((readl(addr) & ~(msk))|(((val) << (shift)) & (msk))),\
		       (addr));\
	} while (0);

/* Boot device */
#define BOOT_DEVICE_NONE	0
#define BOOT_DEVICE_XIP		1
#define BOOT_DEVICE_XIPWAIT	2
#define BOOT_DEVICE_NAND	3
#define BOOT_DEVICE_ONE_NAND	4
#define BOOT_DEVICE_MMC1	5
#define BOOT_DEVICE_MMC2	6

/* Boot type */
#define	MMCSD_MODE_UNDEFINED	0
#define MMCSD_MODE_RAW		1
#define MMCSD_MODE_FAT		2

/* Magic number passed from SPL to U-Boot */
#define OMAP_SPL_TO_UBOOT_MAGIC_NUMBER	0xDEADBEEF

/* HW Init Context */
#define OMAP_INIT_CONTEXT_SPL			0
#define OMAP_INIT_CONTEXT_XIP_UBOOT		1
#define OMAP_INIT_CONTEXT_UBOOT_LOADED_BY_SPL	2
#define OMAP_INIT_CONTEXT_UBOOT_LOADED_BY_CH	3

u32 omap_boot_device(void);
u32 omap_boot_mode(void);
void preloader_console_init(void);

#endif /* _OMAP_COMMON_H_ */
