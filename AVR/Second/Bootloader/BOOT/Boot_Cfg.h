/*
 * Boot_Cfg.h
 *
 * Created: 06.05.2016 01:25:04
 *  Author: AP
 */ 


#ifndef BOOT_CFG_H_
#define BOOT_CFG_H_

#include "PR_DEF.h"

#define BOOT_SIZE_CONFIG_11                                     256

#define BOOT_SIZE_CONFIG_10                                     512

#define BOOT_SIZE_CONFIG_01                                     1024

#define BOOT_SIZE_CONFIG_00                                     2048


/**
 * @brief Size of the Bootloader
 *
 * The size of the bootloader depands on the BOOTSZ Fuse bits
 * The defines above BOOT_SIZE_CONFIG_XX can be used to set the 
 * bootloader size in the software. Don't forget to set the correct 
 * fuse bits.
 * Defintion:
 * BOOT_SIZE_CONFIG_<BOOTSZ1><BOOTSZ0>
 */
#define BOOT_LOADER_SIZE_CFG                    BOOT_SIZE_CONFIG_00


#define BOOT_FLASH_SIZE                                      0x3FFF

/**
 * @brief Application Start Address
 *
 * Address of the Application.
 */
#define BOOT_APPLICATION_ADDRESS                            0x0000
/**
 * @brief Bootloader Address
 *
 * Address of the Bootloader.
 */
#define BOOT_BOOTLOADER_ADDRESS                      ((uint16_t*)(BOOT_FLASH_SIZE - BOOT_LOADER_SIZE_CFG))




#endif /* BOOT_CFG_H_ */