/*
 * Copyright (C) 2010 Trusted Logic S.A.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#define PN547_MAGIC	0xE9

/*
 * PN544 power control via ioctl
 * PN544_SET_PWR(0): power off
 * PN544_SET_PWR(1): power on
 * PN544_SET_PWR(>1): power on with firmware download enabled
 */
#define PN547_SET_PWR	_IOW(PN547_MAGIC, 0x01, unsigned int)

/*
 * SPI Request NFCC to enable p61 power, only in param
 * Only for SPI
 * level 1 = Enable power
 * level 0 = Disable power
 */
#define P61_SET_SPI_PWR    _IOW(PN547_MAGIC, 0x02, unsigned int)

/* SPI or DWP can call this ioctl to get the current
 * power state of P61
 *
*/
#define P61_GET_PWR_STATUS    _IOR(PN547_MAGIC, 0x03, unsigned int)

/* DWP side this ioctl will be called
 * level 1 = Wired access is enabled/ongoing
 * level 0 = Wired access is disalbed/stopped
*/
#define P61_SET_WIRED_ACCESS _IOW(PN547_MAGIC, 0x04, unsigned int)
#define P547_SET_NFC_SERVICE_PID _IOW(PN547_MAGIC, 0x05, long)

#define P547_GET_ESE_ACCESS _IOW(PN547_MAGIC, 0x06, long)
#define P547_REL_SVDD_WAIT _IOW(PN547_MAGIC, 0x07, long)

/* SPI or DWP can call this ioctl to get the current
 * power state of P61
*/
#define PN547_SET_DWNLD_STATUS    _IOW(PN547_MAGIC, 0x09, long)


#define NFC_I2C_LDO_ON	1
#define NFC_I2C_LDO_OFF	0

typedef enum p61_access_state{
	P61_STATE_INVALID = 0x0000,
	P61_STATE_IDLE = 0x0100, /* p61 is free to use */
	P61_STATE_WIRED = 0x0200,  /* p61 is being accessed by DWP (NFCC)*/
	P61_STATE_SPI = 0x0400, /* P61 is being accessed by SPI */
	P61_STATE_DWNLD = 0x0800, /* NFCC fw download is in progress */
	P61_STATE_SPI_PRIO = 0x1000, /*Start of p61 access by SPI on priority*/
	P61_STATE_SPI_PRIO_END = 0x2000, /*End of p61 access by SPI on priority*/
	P61_STATE_SPI_END = 0x4000,
    P61_STATE_JCP_DWNLD = 0x8000,	/* JCOP downlad in progress */	
	P61_STATE_SPI_SVDD_SYNC_START = 0x0001, /*ESE_VDD Low req by SPI*/
	P61_STATE_SPI_SVDD_SYNC_END = 0x0002, /*ESE_VDD is Low by SPI*/
	P61_STATE_DWP_SVDD_SYNC_START = 0x0003, /*ESE_VDD  Low req by Nfc*/
	P61_STATE_DWP_SVDD_SYNC_END = 0x0004, /*ESE_VDD is Low by Nfc*/
}p61_access_state_t;

typedef enum jcop_dwnld_state{
	JCP_DWNLD_IDLE,                         /* jcop dwnld is not ongoing*/
	JCP_DWNLD_INIT,                         /* jcop dwonload init state*/
	JCP_DWNLD_START,                        /* download started */
	JCP_SPI_DWNLD_COMPLETE,                 /* jcop download complete in spi interface*/
	JCP_DWP_DWNLD_COMPLETE,                 /* jcop download complete */
} jcop_dwnld_state_t;

