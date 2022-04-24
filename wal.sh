#!/bin/sh
# This script enables wal support in dwm using the Xresources patch.
# Written by speedie
# https://github.com/speedie-de/dwm

WAL_VARS()
{
  COLORLIST=~/.cache/wal/colors
  XRESOURCES=~/.cache/wal/colors.Xresources
}

WAL_DIE()
{
echo "Could not set colors" && exit 1
}

WAL_COLORS()
{
  COLOR_01=$(sed -n 8,8p $COLORLIST)
  COLOR_02=$(sed -n 1,1p $COLORLIST)
  COLOR_03=$(sed -n 10,10p $COLORLIST)
  COLOR_04=$(sed -n 8,8p $COLORLIST)
  COLOR_05=$(sed -n 11,11p $COLORLIST)
  COLOR_06=$(sed -n 9,9p $COLORLIST)
  TAGCOLOR_01=$(sed -n 2,2p $COLORLIST)
  TAGCOLOR_01_TEXT=$(sed -n 3,3p $COLORLIST)
  TAGCOLOR_02=$(sed -n 4,4p $COLORLIST)
  TAGCOLOR_02_TEXT=$(sed -n 5,5p $COLORLIST)
  TAGCOLOR_03=$(sed -n 6,6p $COLORLIST)
  TAGCOLOR_03_TEXT=$(sed -n 7,7p $COLORLIST)
  TAGCOLOR_04=$(sed -n 10,10p $COLORLIST)
  TAGCOLOR_04_TEXT=$(sed -n 12,12p $COLORLIST)
  TAGCOLOR_05=$(sed -n 13,13p $COLORLIST)
  TAGCOLOR_05_TEXT=$(sed -n 14,14p $COLORLIST)
  TAGCOLOR_06=$(sed -n 15,15p $COLORLIST)
  TAGCOLOR_06_TEXT=$(sed -n 16,16p $COLORLIST)
  TAGCOLOR_07=$(sed -n 8,8p $COLORLIST)
  TAGCOLOR_07_TEXT=$(sed -n 1,1p $COLORLIST)
  TAGCOLOR_08=$(sed -n 9,9p $COLORLIST)
  TAGCOLOR_08_TEXT=$(sed -n 11,11p $COLORLIST)
  TAGCOLOR_09=$(sed -n 2,2p $COLORLIST)
  TAGCOLOR_09_TEXT=$(sed -n 16,16p $COLORLIST)
  TAGCOLOR_STATIC_01="#FFFFFF" # Always white
  TAGCOLOR_STATIC_02="#000000" # Always black
}

WAL_DMENU()
{
  wal_dmenu.sh # If you're using speedie's dmenu then apply dmenu colors too
}

WAL_WRITE()
{
  echo "!!dwm" >> $XRESOURCES
  echo "dwm.col_textnorm:         $COLOR_01" >> $XRESOURCES
  echo "dwm.col_background:       $COLOR_02" >> $XRESOURCES
  echo "dwm.col_backgroundmid:    $COLOR_03" >> $XRESOURCES
  echo "dwm.col_textsel:          $COLOR_04" >> $XRESOURCES
  echo "dwm.col_windowbordernorm: $COLOR_05" >> $XRESOURCES
  echo "dwm.col_windowbordersel:  $COLOR_06" >> $XRESOURCES
  echo "dwm.col_tag1:             $TAGCOLOR_01" >> $XRESOURCES
  echo "dwm.col_tag1_text:        $TAGCOLOR_STATIC_01" >> $XRESOURCES
  echo "dwm.col_tag2:             $TAGCOLOR_02" >> $XRESOURCES
  echo "dwm.col_tag2_text:        $TAGCOLOR_STATIC_01" >> $XRESOURCES
  echo "dwm.col_tag3:             $TAGCOLOR_03" >> $XRESOURCES
  echo "dwm.col_tag3_text:        $TAGCOLOR_STATIC_01" >> $XRESOURCES
  echo "dwm.col_tag4:             $TAGCOLOR_04" >> $XRESOURCES
  echo "dwm.col_tag4_text:        $TAGCOLOR_STATIC_01" >> $XRESOURCES
  echo "dwm.col_tag5:             $TAGCOLOR_05" >> $XRESOURCES
  echo "dwm.col_tag5_text:        $TAGCOLOR_STATIC_01" >> $XRESOURCES
  echo "dwm.col_tag6:             $TAGCOLOR_06" >> $XRESOURCES
  echo "dwm.col_tag6_text:        $TAGCOLOR_STATIC_01" >> $XRESOURCES
  echo "dwm.col_tag7:             $TAGCOLOR_07" >> $XRESOURCES
  echo "dwm.col_tag7_text:        $TAGCOLOR_STATIC_01" >> $XRESOURCES
  echo "dwm.col_tag8:             $TAGCOLOR_08" >> $XRESOURCES
  echo "dwm.col_tag8_text:        $TAGCOLOR_STATIC_01" >> $XRESOURCES
  echo "dwm.col_tag9:             $TAGCOLOR_09" >> $XRESOURCES
  echo "dwm.col_tag9_text:        $TAGCOLOR_STATIC_01" >> $XRESOURCES
}

WAL_SET()
{
  xrdb -merge ~/.cache/wal/colors.Xresources
}

WAL_DMENU # Comment if you're not using my build of dmenu/one that supports .Xresources
WAL_VARS || WAL_DIE
WAL_COLORS || WAL_DIE
WAL_WRITE || WAL_DIE
WAL_SET || WAL_DIE
