/*
 * (C) Copyright 2010
 * Texas Instruments Incorporated.
 * Steve Sakoman  <steve@sakoman.com>
 *
 * Configuration settings for the TI OMAP4 Panda board.
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
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#ifndef __CONFIG_H
#define __CONFIG_H

/*
 * High Level Configuration Options
 */
#define CONFIG_ARMV7		1	/* This is an ARM V7 CPU core */
#define CONFIG_OMAP		1	/* in a TI OMAP core */
#define CONFIG_OMAP44XX		1	/* which is a 44XX */
#define CONFIG_OMAP4430		1	/* which is in a 4430 */
#define CONFIG_PANDA		1	/* working with Panda */
#define CONFIG_ARCH_CPU_INIT

/* Get CPU defs */
#include <asm/arch/cpu.h>
#include <asm/arch/omap4.h>

/* Display CPU and Board Info */
#define CONFIG_DISPLAY_CPUINFO		1
#define CONFIG_DISPLAY_BOARDINFO	1

/* Keep L2 Cache Disabled */
#define CONFIG_L2_OFF			1	/* XXX: */

/* Clock Defines */
#define V_OSCK			38400000	/* Clock output from T2 */
#define V_SCLK                   V_OSCK

#undef CONFIG_USE_IRQ				/* no support for IRQs */
#define CONFIG_MISC_INIT_R

#define CONFIG_CMDLINE_TAG		1	/* enable passing of ATAGs */
#define CONFIG_SETUP_MEMORY_TAGS	1
#define CONFIG_REVISION_TAG		1	/* XXX: */
#define CONFIG_INITRD_TAG		1

#define CONFIG_OF_LIBFDT		1

/*
 * Size of malloc() pool
 * Total Size Environment - 256k
 * Malloc - add 256k
 */
#define CONFIG_ENV_SIZE			(4 << 10)	/* XXX: */
#define CONFIG_SYS_MALLOC_LEN		(CONFIG_ENV_SIZE + (512 << 10))
#define CONFIG_SYS_CA9_VECTOR_BASE	SRAM_ROM_VECT_BASE

/*
 * Hardware drivers
 */

/*
 * serial port - NS16550 compatible
 */
#define V_NS16550_CLK			48000000

#define CONFIG_SYS_NS16550
#define CONFIG_SYS_NS16550_SERIAL
#define CONFIG_SYS_NS16550_REG_SIZE	(-4)
#define CONFIG_SYS_NS16550_CLK		V_NS16550_CLK
#define CONFIG_SYS_NS16550_COM3		UART3_BASE
#define CONFIG_CONS_INDEX		3

/*#define CONFIG_ENV_IS_NOWHERE */
#define CONFIG_SYS_BAUDRATE_TABLE	{4800, 9600, 19200, 38400, 57600,\
					115200}
#define CONFIG_BAUDRATE			115200

/* I2C  */
#define CONFIG_HARD_I2C			1
#define CONFIG_SYS_I2C_SPEED		100000	/* XXX: 400k? */
#define CONFIG_SYS_I2C_SLAVE		1
#define CONFIG_SYS_I2C_BUS		0
#define CONFIG_SYS_I2C_BUS_SELECT	1
#define CONFIG_DRIVER_OMAP34XX_I2C	1
#define CONFIG_I2C_MULTI_BUS		1

/* TWL6030 */
#define CONFIG_TWL6030_POWER		1

/* MMC */
#define CONFIG_MMC			1
#define CONFIG_OMAP_HSMMC		1
#define CONFIG_GENERIC_MMC		1
#define CONFIG_SYS_MMC_SET_DEV		1
#define CONFIG_DOS_PARTITION		1

/* MTD */
#define CONFIG_MTD_DEVICE	/* needed for mtdparts commands */
#define CONFIG_MTD_PARTITIONS	/* needed for mtdparts commands */
#define MTDIDS_DEFAULT			"nand0=nand"
#define MTDPARTS_DEFAULT		"mtdparts=nand:512k(x-loader)," \
					"1920k(u-boot),128k(u-boot-env)," \
					"4m(kernel),-(fs)"	/* XXX: */

/* NAND */
#define CONFIG_NAND_OMAP_GPMC
#define CONFIG_SYS_NAND_QUIET_TEST	1
#define CONFIG_SYS_MAX_NAND_DEVICE	1	/* Max number of NAND devices */
#define GPMC_NAND_ECC_LP_x16_LAYOUT	1
#define CONFIG_SYS_NAND_ADDR		GPMC_BASE
#define CONFIG_SYS_NAND_BASE		GPMC_BASE
	/* physical address to access nand at CS0 */

/* USB */
/*#define CONFIG_MUSB_HCD			1 */
#define CONFIG_MUSB_UDC			1
#define CONFIG_USB_OMAP3		1

/* USB device configuration */
#define CONFIG_USB_DEVICE		1
#ifndef CONFIG_PRELOADER
#define CONFIG_USB_TTY			1
#define CONFIG_CONSOLE_MUX		1
#endif
#define CONFIG_SYS_CONSOLE_IS_IN_ENV	1

/* Status LED */
/*#define CONFIG_STATUS_LED		1 */
#define CONFIG_BOARD_SPECIFIC_LED	1
#define STATUS_LED_BIT			0x01
#define STATUS_LED_STATE		STATUS_LED_ON
#define STATUS_LED_PERIOD		(CONFIG_SYS_HZ / 2)
#define STATUS_LED_BIT1			0x02
#define STATUS_LED_STATE1		STATUS_LED_ON
#define STATUS_LED_PERIOD1		(CONFIG_SYS_HZ / 2)
#define STATUS_LED_BOOT			STATUS_LED_BIT
#define STATUS_LED_GREEN		STATUS_LED_BIT1

/* commands to include */
#include <config_cmd_default.h>

/* Enabled commands */
#define CONFIG_CMD_I2C		/* I2C serial bus support	*/

#define CONFIG_CMD_MMC		/* MMC support                  */
#define CONFIG_CMD_FAT		/* FAT support                  */
/*#define CONFIG_CMD_EXT2	// EXT2 Support                 */

#define CONFIG_CMD_MTDPARTS	/* Enable MTD parts commands	*/
#define CONFIG_CMD_NAND		/* NAND support			*/
#define CONFIG_CMD_UBI		/* UBI support			*/
#define CONFIG_RBTREE

#define CONFIG_CMD_LED		/* LED support			*/
/*#define CONFIG_CMD_USB          // USB support			*/
#define CONFIG_CMD_CACHE

/* Disabled commands */
#undef CONFIG_CMD_NET
#undef CONFIG_CMD_NFS
#undef CONFIG_CMD_FPGA		/* FPGA configuration Support   */
#undef CONFIG_CMD_IMLS		/* List all found images        */
#define CONFIG_SYS_NO_FLASH	1

/*
 * Environment setup
 */

#define CONFIG_BOOTDELAY	1

#define CONFIG_ENV_OVERWRITE

/* XXX: omapdss.def_disp=hdmi */
#define CONFIG_EXTRA_ENV_SETTINGS \
	"optargs=panic=1 splash\0" \
	"mmcdev=0\0mpurate=auto\0usbtty=cdc_acm\0" \
	"rdaddr=0x81600000\0loadaddr=0x82000000\0" \
	"videospec=vram=32M omapfb.vram=0:16M,1:16M\0" \
	"memargs=mem=456M@0x80000000 mem=512M@0xA0000000\0" \
	"console=console=ttyO2,115200n8 consoleblank=0 " \
		"androidboot.console=ttyO2 init=/init quiet\0" \
	"nfsargs=setenv bootargs root=/dev/nfs rw " \
		"${console} ${memargs} ${videospec} ${optargs} " \
		"nfsroot=/home/mhfan/devel/beagle/rootfs,nolock " \
		"ip=192.168.1.53:192.168.1.54:192.168.1.1\0" \
	"mmcargs=setenv bootargs " \
		"${console} ${memargs} ${videospec} ${optargs} " \
		"root=/dev/mmcblk0p2 rw rootfstype=ext4 rootwait\0" \
	"nandargs=setenv bootargs " \
		"${console} ${memargs} ${videospec} ${optargs} " \
		"root=/dev/mtdblock4 rw rootfstype=yaffs2\0" \
	"irfsargs=setenv bootargs rdinit=/sbin/init " \
		"${console} ${memargs} ${videospec} ${optargs}\0" \
	"ramargs=setenv bootargs root=/dev/ram0 rw " \
		"${console} ${memargs} ${videospec} ${optargs} " \
		"ramdisk_size=32768 initrd=${rdaddr},32M\0" \
	"ubifsargs=setenv bootargs " \
		"${console} ${memargs} ${videospec} ${optargs} " \
		"root=ubi0:beagleroot ubi.mtd=4 rw rootfstype=ubifs\0" \
	"loadbootenv=fatload mmc ${mmcdev} ${loadaddr} uEnv.txt\0" \
	"loadbootscript=fatload mmc ${mmcdev} ${loadaddr} boot.scr\0" \
	"bootscript=echo Running bootscript from mmc${mmcdev} ...; " \
		"source ${loadaddr}\0" \
	"importbootenv=echo Importing environment from mmc ...; " \
		"env import -t ${loadaddr} ${filesize}\0" \
	"loaduimage=fatload mmc ${mmcdev} ${loadaddr} uImage\0" \
	"loadirfs=fatload mmc ${mmcdev} ${rdaddr} rootfs.uboot\0" \
	"loadramdisk=fatload mmc ${mmcdev} ${rdaddr} ramdisk.gz\0" \
	"irfsboot=echo Booting from initramfs ...; run irfsargs; " \
		"bootm ${loadaddr} ${rdaddr}\0" \
	"ramboot=echo Booting from ramdisk.gz ...; run ramargs; " \
		"bootm ${loadaddr}\0" \
	"mmcboot=echo Booting from mmc ...; run mmcargs; bootm ${loadaddr}\0" \
	"nandboot=echo Booting from nand ...; run nandargs; " \
		"nand read ${loadaddr} 280000 400000; bootm ${loadaddr}\0" \
	"mtdparts=" MTDPARTS_DEFAULT "\0" \
	"stdout=serial,usbtty\0stdin=serial,usbtty\0stderr=serial,usbtty\0"
/*	"nandboot=echo Booting from nand ...; run nandargs; nboot kernel\0" */

#define CONFIG_BOOTCOMMAND \
	"if mmc rescan ${mmcdev}; then " \
	    "echo SD/MMC found on device ${mmcdev}; " \
	    "if run loadbootscript; then run bootscript; fi; " \
	    "if run loadbootenv; then " \
		"run importbootenv; " \
		"if test -n $uenvcmd; then " \
		    "echo Running uenvcmd ...; " \
		    "run uenvcmd; " \
		"fi; " \
	    "fi; " \
	    "if run loaduimage; then " \
		"if run loadirfs; then run irfsboot; fi; " \
		"if run loadramdisk; then run ramboot; fi; " \
		"run mmcboot; " \
	    "fi; " \
	"fi; " \
	"run nandboot; " \

#define CONFIG_AUTO_COMPLETE		1

/*
 * Miscellaneous configurable options
 */

#define CONFIG_SYS_LONGHELP	/* undef to save memory, XXX: */
#define CONFIG_SYS_HUSH_PARSER	/* use "hush" command parser */
#define CONFIG_SYS_PROMPT_HUSH_PS2	"> "
#define CONFIG_SYS_PROMPT		"Panda # "
#define CONFIG_SYS_CBSIZE		256
/* Print Buffer Size */
#define CONFIG_SYS_PBSIZE		(CONFIG_SYS_CBSIZE + \
					sizeof(CONFIG_SYS_PROMPT) + 16)
#define CONFIG_SYS_MAXARGS		16
/* Boot Argument Buffer Size */
#define CONFIG_SYS_BARGSIZE		(CONFIG_SYS_CBSIZE)

/*
 * memtest setup
 */
#define CONFIG_SYS_MEMTEST_START	0x80000000
#define CONFIG_SYS_MEMTEST_END		(CONFIG_SYS_MEMTEST_START + (32 << 20))

/* Default load address */
#define CONFIG_SYS_LOAD_ADDR		0x80000000

/* Use General purpose timer 1 */
#define CONFIG_SYS_TIMERBASE		GPT2_BASE
#define CONFIG_SYS_PTV			2	/* Divisor: 2^(PTV+1) => 8 */
#define CONFIG_SYS_HZ			1000

/*
 * Stack sizes
 *
 * The stack sizes are set up in start.S using the settings below
 */
#define CONFIG_STACKSIZE	(128 << 10)	/* Regular stack */
#ifdef CONFIG_USE_IRQ
#define CONFIG_STACKSIZE_IRQ	(4 << 10)	/* IRQ stack */
#define CONFIG_STACKSIZE_FIQ	(4 << 10)	/* FIQ stack */
#endif

/*
 * SDRAM Memory Map
 * Even though we use two CS all the memory
 * is mapped to one contiguous block
 */
#define CONFIG_NR_DRAM_BANKS	1

#define CONFIG_SYS_SDRAM_BASE		0x80000000
#define CONFIG_SYS_INIT_RAM_ADDR	0x4030D800
#define CONFIG_SYS_INIT_RAM_SIZE	0x800
#define CONFIG_SYS_INIT_SP_ADDR		(CONFIG_SYS_INIT_RAM_ADDR + \
					 CONFIG_SYS_INIT_RAM_SIZE - \
					 GENERATED_GBL_DATA_SIZE)

/* Defines for Clock init */
#define CONFIG_SYS_OMAP4_ABE_SYSCK

/* Defines for SDRAM init */
#ifndef CONFIG_SYS_EMIF_PRECALCULATED_TIMING_REGS
#define CONFIG_SYS_AUTOMATIC_SDRAM_DETECTION	1
#define CONFIG_SYS_DEFAULT_LPDDR2_TIMINGS	1
#endif

/* Defines for SPL */
#define CONFIG_SPL
#define CONFIG_SYS_SPL_TEXT_BASE	0x40304360
#define CONFIG_SYS_SPL_MAX_SIZE		0x7800	/* 30 K */
	/* XXX: L3 OCM_RAM 0x40300000 + 56K */
#define CONFIG_SYS_SPL_STACK		LOW_LEVEL_SRAM_STACK

#define CONFIG_SYS_MMCSD_RAW_MODE_U_BOOT_SECTOR	0x300 /* address 0x60000 */
#define CONFIG_SYS_U_BOOT_MAX_SIZE_SECTORS	0x200 /* 256 KB */
#define CONFIG_SYS_MMC_SD_FAT_BOOT_PARTITION	1

#define CONFIG_SYS_SPL_BSS_START_ADDR		0x80000000
#define CONFIG_SYS_SPL_BSS_MAX_SIZE		0x80000		/* 512 KB */

/*-----------------------------------------------------------------------
 * FLASH and environment organization
 */

/* Configure the PISMO */
#define PISMO1_NAND_SIZE		GPMC_SIZE_128M
#define PISMO1_ONEN_SIZE		GPMC_SIZE_128M

#define CONFIG_SYS_MONITOR_LEN		(256 << 10)	/* Reserve 2 sectors */

#if defined(CONFIG_CMD_NAND)
#define CONFIG_SYS_FLASH_BASE		PISMO1_NAND_BASE
#endif

/* Monitor at start of flash */
#define CONFIG_SYS_MONITOR_BASE		CONFIG_SYS_FLASH_BASE
#define CONFIG_SYS_ONENAND_BASE		ONENAND_MAP

#define CONFIG_ENV_IS_IN_NAND		1
#define ONENAND_ENV_OFFSET		0x260000 /* environment starts here */
#define SMNAND_ENV_OFFSET		0x260000 /* environment starts here */

#define CONFIG_SYS_ENV_SECT_SIZE	(128 << 10)	/* 128 KiB */
#define CONFIG_ENV_OFFSET		SMNAND_ENV_OFFSET
#define CONFIG_ENV_ADDR			SMNAND_ENV_OFFSET

#endif /* __CONFIG_H */
