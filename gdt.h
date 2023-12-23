/******************************************************************************
\Project MyKernel (Writing my own OS)

\Author : Oussama BOUKSIM

\File : gdt.h

\Creation date : 12/02/2023

\Copyright (C) 2023 - All rights reserved.
*******************************************************************************/
#ifndef __GDT_H
#define __GDT_H

#include "Types.h"

/*
  -------------------------------------------------------------------------
  |        |Fl || Li|        |                          |                 |
  |  Base  |ag || mi|  Type  |           Base           |      Limit      |
  |        |s  || t |        |                          |                 |
  |--------|--------|--------|--------|--------|--------|--------|--------|

*/


class GlobalDescriptorTable {
public:
  class SegmentDescriptor {
  private:
    uint16_t limit_lo;
    uint16_t base_lo;
    uint8_t base_hi;
    uint8_t type;
    uint8_t flags_limit_hi;
    uint8_t base_vhi;

  public:
    SegmentDescriptor(uint32_t base, uint32_t limit, uint8_t type);
    uint32_t Base();
    uint32_t Limit();
  };

  SegmentDescriptor nullSegmentSelector;
  SegmentDescriptor unusedSegmentSelector;
  SegmentDescriptor codeSegmentSelector;
  SegmentDescriptor dataSegmentSelector;

  GlobalDescriptorTable(/* args */);
  ~GlobalDescriptorTable();

  uint16_t CodeSegmentSelector();
  uint16_t DataSegmentSelector();
};

#endif