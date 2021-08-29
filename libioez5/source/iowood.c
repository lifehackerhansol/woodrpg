/*
    iowood.c modified for EZ-Flash V
    Copyright (C) 2010 yellow wood goblin
    Copyright (C) 2021 lifehackerhansol

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#include <nds.h>
bool EZSD_StartUp(void);
bool EZSD_IsInserted(void);
bool EZSD_ReadSectors(u32 sector, u8 numSecs, void* buffer);
bool EZSD_WriteSectors(u32 sector, u8 numSecs, void* buffer);
bool EZSD_ClearStatus(void) ;
bool shutdown(void);
#define NAND 0
#define SD   1

void NandFast(void)
{
}

void NandFlush(void)
{
}

int ioWoodInit(unsigned char aDrive)
{
  if(aDrive==NAND) return (EZSD_StartUp()&&EZSD_IsInserted());
  return FALSE;
}

int ioWoodStatus(unsigned char aDrive)
{
  if(aDrive==NAND) return EZSD_IsInserted();
  return FALSE;
}

int ioWoodRead(unsigned char aDrive,unsigned char* aBuffer,unsigned long aSector,unsigned char aCount)
{
  if(aDrive==NAND) return EZSD_ReadSectors(aSector,aCount,aBuffer);
  return FALSE;
}

int ioWoodWrite(unsigned char aDrive,const unsigned char* aBuffer,unsigned long aSector,unsigned char aCount)
{
  if(aDrive==NAND) return EZSD_WriteSectors(aSector,aCount,(void*)aBuffer);
  return FALSE;
}

void ioWoodSync(unsigned char aDrive)
{
  if(aDrive==NAND) EZSD_ClearStatus();
}
