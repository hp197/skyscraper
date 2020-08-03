/***************************************************************************
 *            platform.cpp
 *
 *  Sat Dec 23 10:00:00 CEST 2017
 *  Copyright 2017 Lars Muldjord
 *  muldjordlars@gmail.com
 ****************************************************************************/
/*
 *  This file is part of skyscraper.
 *
 *  skyscraper is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  skyscraper is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with skyscraper; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA.
 */

#include <iostream>
#include <QFile>
#include <QProcess>
#include <QDir>

#include "platform.h"

Platform::Platform()
{
}

Platform::~Platform()
{
}

QStringList Platform::getPlatforms()
{
  QStringList platforms;
  platforms.append("3do");
  platforms.append("3ds");
  platforms.append("adam");
  platforms.append("advision");
  platforms.append("amiga");
  platforms.append("amigacd32");
  platforms.append("amigacdtv");
  platforms.append("amstradcpc");
  platforms.append("apple2");
  platforms.append("apple2gs");
  platforms.append("arcade");
  platforms.append("arcadia");
  platforms.append("astrocade");
  platforms.append("atari800");
  platforms.append("atari2600");
  platforms.append("atari5200");
  platforms.append("atari7800");
  platforms.append("atarijaguar");
  platforms.append("atarilynx");
  platforms.append("atarist");
  platforms.append("atarixegs");
  platforms.append("c16");
  platforms.append("c64");
  platforms.append("c128");
  platforms.append("cdi");
  platforms.append("channelf");
  platforms.append("coco");
  platforms.append("coleco");
  platforms.append("daphne");
  platforms.append("dragon32");
  platforms.append("dreamcast");
  platforms.append("electron");
  platforms.append("fba");
  platforms.append("fds");
  platforms.append("gameandwatch");
  platforms.append("gamegear");
  platforms.append("gamepock");
  platforms.append("gb");
  platforms.append("gba");
  platforms.append("gbc");
  platforms.append("gc");
  platforms.append("genesis");
  platforms.append("gx4000");
  platforms.append("intellivision");
  platforms.append("mame-advmame");
  platforms.append("mame-libretro");
  platforms.append("mame-mame4all");
  platforms.append("mastersystem");
  platforms.append("megacd");
  platforms.append("megadrive");
  platforms.append("megaduck");
  platforms.append("msx");
  platforms.append("msx2");
  platforms.append("msx2plus");
  platforms.append("msxturbor");
  platforms.append("n64");
  platforms.append("nds");
  platforms.append("neogeo");
  platforms.append("neogeocd");
  platforms.append("nes");
  platforms.append("ngp");
  platforms.append("ngpc");
  platforms.append("openbor");
  platforms.append("oric");
  platforms.append("pc");
  platforms.append("pc88");
  platforms.append("pc98");
  platforms.append("pcengine");
  platforms.append("pcenginecd");
  platforms.append("pcfx");
  platforms.append("pokemini");
  platforms.append("ports");
  platforms.append("ps2");
  platforms.append("psp");
  platforms.append("psx");
  platforms.append("saturn");
  platforms.append("samcoupe");
  platforms.append("satellaview");
  platforms.append("scummvm");
  platforms.append("scv");
  platforms.append("sega32x");
  platforms.append("segacd");
  platforms.append("sg-1000");
  platforms.append("sgb");
  platforms.append("snes");
  platforms.append("snesmsu1");
  platforms.append("steam");
  platforms.append("sufami");
  platforms.append("supergrafx");
  platforms.append("supervision");
  platforms.append("ti99");
  platforms.append("thomson");
  platforms.append("trs-80");
  platforms.append("vectrex");
  platforms.append("vic20");
  platforms.append("videopac");
  platforms.append("virtualboy");
  platforms.append("wii");
  platforms.append("wiiu");
  platforms.append("wonderswan");
  platforms.append("wonderswancolor");
  platforms.append("x1");
  platforms.append("x68000");
  platforms.append("zmachine");
  platforms.append("zx81");
  platforms.append("zxspectrum");

  return platforms;
}

QStringList Platform::getScrapers(QString platform)
{
  QStringList scrapers;
  QStringList screenscraper_platforms = {
    "3do", "3ds", "adam", "advision", "amiga", "amigacd32",
    "amigacdtv", "aga", "amstradcpc", "apple2", "apple2gs",
    "arcade", "arcadia", "astrocade", "atari800",
    "atari2600", "atari5200", "atari7800", "atarijaguar",
    "atarilynx", "atarist", "atarixegs", "c64", "cdi",
    "channelf", "coco", "coleco", "daphne", "dragon32",
    "dreamcast", "electron", "fba", "fds", "gameandwatch",
    "gamegear", "gamepock", "gb", "gba", "gbc", "gc",
    "genesis", "gx4000", "intellivision", "mame-advmame",
    "mame-libretro", "mame-mame4all", "mastersystem",
    "megacd", "megadrive", "megaduck", "msx", "msx2",
    "msx2plus", "msxturbor", "n64", "nds", "neogeo",
    "neogeocd", "nes", "ngp", "ngpc", "openbor", "oric",
    "pc", "pc88", "pc98", "pcengine", "pcenginecd",
    "pcfx", "pokemini", "ports", "ps2", "psp", "psx",
    "saturn", "samcoupe", "satellaview", "scummvm", "scv",
    "sega32x", "segacd", "sg-1000", "sgb", "snes",
    "snesmsu1", "sufami", "supergrafx", "supervision",
    "ti99", "thomson", "trs-80", "vectrex", "vic20",
    "videopac", "virtualboy", "wii", "wiiu", "wonderswan",
    "wonderswancolor", "x1", "x68000", "zx81", "zxspectrum"
  };

  foreach (const QString &str, screenscraper_platforms)
  {
      if (str == platform)
      {
          scrapers.append("screenscraper");
      }
  }

  if(platform == "amiga") {
    scrapers.append("openretro");
  } else if(platform == "arcade") {
    scrapers.append("arcadedb");
  } else if(platform == "fba") {
    scrapers.append("arcadedb");
  } else if(platform == "mame-advmame") {
    scrapers.append("arcadedb");
  } else if(platform == "mame-libretro") {
    scrapers.append("arcadedb");
  } else if(platform == "mame-mame4all") {
    scrapers.append("arcadedb");
  } else if(platform == "neogeo") {
    scrapers.append("arcadedb");
  } else if(platform == "pc") {
    scrapers.append("thegamesdb");
  } else if(platform == "pc88") {
    scrapers.append("thegamesdb");
  } else if(platform == "pc98") {
    scrapers.append("thegamesdb");
  } else if(platform == "ports") {
    scrapers.append("thegamesdb");
  } else if(platform == "ps2") {
    scrapers.append("thegamesdb");
  } else if(platform == "psx") {
    scrapers.append("thegamesdb");
  } else if(platform == "scummvm") {
    scrapers.append("thegamesdb");
  } else if(platform == "wii") {
    scrapers.append("thegamesdb");
  } else if(platform == "wiiu") {
    scrapers.append("thegamesdb");
  } else if(platform  == "zmachine") {
    scrapers.append("thegamesdb");
  } else if(platform  == "zxspectrum") {
    scrapers.append("worldofspectrum");
  }

  scrapers.append("cache");

  return scrapers;
}

QString Platform::getFormats(QString platform, QString extensions, QString addExtensions)
{
  if(!extensions.isEmpty() && extensions.contains("*.")) {
    return extensions;
  }

  QString formats = "*.zip *.7z *.ml "; // The last ' ' IS IMPORTANT!!!!!
  if(!addExtensions.isEmpty() && addExtensions.contains("*.")) {
    formats.append(addExtensions);
  }
  if(formats.right(1) != " ") {
    formats.append(" ");
  }

  QHash<QString, QString> format_hash;
  format_hash["3do"]             = "*.cue *.iso *.chd";
  format_hash["3ds"]             = "*.3ds";
  format_hash["adam"]            = "*.dsk";
  format_hash["advision"]        = "*.bin";
  format_hash["amiga"]           = "*.uae *.adf *.dms *.adz *.rp9 *.lha *.cue *.img *.iso *.hdf";
  format_hash["amigacd32"]       = "*.uae *.adf *.dms *.adz *.rp9 *.lha *.cue *.img *.iso *.hdf";
  format_hash["amigacdtv"]       = "*.uae *.adf *.dms *.adz *.rp9 *.lha *.cue *.img *.iso *.hdf";
  format_hash["amstradcpc"]      = "*.dsk *.cpc";
  format_hash["apple2"]          = "*.dsk";
  format_hash["apple2gs"]        = "*.gsp";
  format_hash["arcade"]          = "*.bin *.dat";
  format_hash["arcadia"]         = "";
  format_hash["astrocade"]       = "*.bin";
  format_hash["atari800"]        = "*.a52 *.bas *.bin *.car *.xex *.atr *.xfd *.dcm *.atr.gz *.xfd.gz";
  format_hash["atari2600"]       = "*.bin *.a26 *.rom *.gz";
  format_hash["atari5200"]       = "*.a52 *.bas *.bin *.car *.xex *.atr *.xfd *.dcm *.atr.gz *.xfd.gz";
  format_hash["atari7800"]       = "*.a78 *.bin";
  format_hash["atarijaguar"]     = "*.j64 *.jag";
  format_hash["atarilynx"]       = "*.lnx";
  format_hash["atarist"]         = "*.st *.stx *.img *.rom *.raw *.ipf *.ctr";
  format_hash["atarixegs"]       = "*.img *.rom *.raw *.com *.bin";
  format_hash["c16"]             = "*.crt *.d64 *.prg *.tap *.t64 *.g64 *.x64 *.vsf";
  format_hash["c64"]             = "*.crt *.d64 *.prg *.tap *.t64 *.g64 *.x64 *.vsf";
  format_hash["c128"]            = "*.crt *.d64 *.prg *.tap *.t64 *.g64 *.x64 *.vsf";
  format_hash["cdi"]             = "*.cdi *.gdi *.iso *.chd *.cue *.m3u";
  format_hash["channelf"]        = "*.bin *.rom *.raw";
  format_hash["coco"]            = "*.cas *.wav *.bas *.asc *.dmk *.jvc *.os9 *.dsk *.vdk *.rom *.ccc *.sna";
  format_hash["coleco"]          = "*.bin *.col *.rom";
  format_hash["daphne"]          = "*.daphne";
  format_hash["dragon32"]        = "*.cas *.wav *.bas *.asc *.dmk *.jvc *.os9 *.dsk *.vdk *.rom *.ccc *.sna";
  format_hash["dreamcast"]       = "*.cdi *.gdi *.iso *.chd *.cue *.m3u";
  format_hash["electron"]        = "*.uef";
  format_hash["fba"]             = "";
  format_hash["fds"]             = "*.fds *.nes";
  format_hash["gameandwatch"]    = "*.mgw";
  format_hash["gamegear"]        = "*.gg";
  format_hash["gamepock"]        = "*.bin";
  format_hash["gb"]              = "*.gb";
  format_hash["gba"]             = "*.gba";
  format_hash["gbc"]             = "*.gbc";
  format_hash["gc"]              = "*.iso *.cso *.gcz *.gcm *.m3u";
  format_hash["genesis"]         = "*.smd *.bin *.gen *.md *.sg";
  format_hash["gx4000"]          = "*.bin";
  format_hash["intellivision"]   = "*.int *.bin";
  format_hash["mame-advmame"]    = "";
  format_hash["mame-libretro"]   = "";
  format_hash["mame-mame4all"]   = "";
  format_hash["mastersystem"]    = "*.sms";
  format_hash["megacd"]          = "*.cue *.iso *.chd";
  format_hash["megadrive"]       = "*.smd *.bin *.gen *.md *.sg";
  format_hash["megaduck"]        = "*.bin";
  format_hash["msx"]             = "*.rom *.mx1 *.col *.dsk";
  format_hash["msx2"]            = "*.rom *.mx2 *.col *.dsk";
  format_hash["msx2plus"]        = "*.rom *.col *.dsk";
  format_hash["msxturbor"]       = "*.rom *.col *.dsk";
  format_hash["n64"]             = "*.z64 *.n64 *.v64";
  format_hash["nds"]             = "*.nds";
  format_hash["neogeo"]          = "";
  format_hash["neogeocd"]        = "*.cue *.iso *.chd";
  format_hash["nes"]             = "*.nes *.smc *.sfc *.fig *.swc *.mgd";
  format_hash["ngp"]             = "*.ngp";
  format_hash["ngpc"]            = "*.ngc";
  format_hash["openbor"]         = "*.pak";
  format_hash["oric"]            = "*.dsk *.tap";
  format_hash["pc"]              = "*.com *.sh *.bat *.exe *.conf";
  format_hash["pc88"]            = "*.d88 *.88d *.cmt *.t88";
  format_hash["pc98"]            = "*.d88 *.d98 *.88d *.98d *.fdi *.xdf *.hdm *.dup *.2hd *.tfd *.hdi *.thd *.nhd *.hdd *.fdd *.cmd *.hdn";
  format_hash["pcengine"]        = "*.pce *.chd *.cue";
  format_hash["pcenginecd"]      = "*.pce *.chd *.cue";
  format_hash["pcfx"]            = "*.img *.iso *.ccd *.cue *.chd";
  format_hash["pokemini"]        = "*.min";
  format_hash["ports"]           = "*.com *.sh *.bat *.exe *.conf";
  format_hash["ps2"]             = "*.iso *.cue *.img *.mdf *.z *.z2 *.bz2 *.dump *.cso *.ima *.gz";
  format_hash["psp"]             = "*.cso *.iso *.pbp";
  format_hash["psx"]             = "*.cue *.cbn *.img *.iso *.m3u *.mdf *.pbp *.toc *.z *.znx *.chd";
  format_hash["saturn"]          = "*.cue *.iso *.mdf *.chd";
  format_hash["samcoupe"]        = "*.sad *.dsk";
  format_hash["satellaview"]     = "*.smc *.sfc *.bin";
  format_hash["scummvm"]         = "*.svm *.scummvm";
  format_hash["scv"]             = "*.bin";
  format_hash["sega32x"]         = "*.32x *.bin *.md *.smd";
  format_hash["segacd"]          = "*.cue *.iso *.chd";
  format_hash["sg-1000"]         = "*.bin *.sg";
  format_hash["sgb"]             = " *.gb *.sgb *.gbc";
  format_hash["snes"]            = "*.smc *.sfc *.fig *.swc *.mgd *.bin";
  format_hash["snesmsu1"]        = "*.smc *.sfc";
  format_hash["sufami"]          = "*.smc *.sfc";
  format_hash["supergrafx"]      = "*.srm";
  format_hash["supervision"]     = "*.sv";
  format_hash["ti99"]            = "*.ctg";
  format_hash["thomson"]         = "*.rom *.bin *.fd *.k7 *.m7 *.qd *.sap *.m5 *.wav";
  format_hash["trs-80"]          = "*.dsk";
  format_hash["vectrex"]         = "*.bin *.gam *.vec";
  format_hash["vic20"]           = "*.crt *.d64 *.prg *.tap *.t64 *.g64 *.x64 *.vsf";
  format_hash["videopac"]        = "*.bin";
  format_hash["virtualboy"]      = "*.vb";
  format_hash["wii"]             = "*.iso *.cso *.gcz *.wbfs";
  format_hash["wiiu"]            = "*.iso *.cso *.gcz *.wbfs *.wud *.wux *.rpx *.app";
  format_hash["wonderswan"]      = "*.ws";
  format_hash["wonderswancolor"] = "*.wsc";
  format_hash["x1"]              = "*.dx1 *.2d *.2hd *.tfd *.d88 *.88d *.hdm *.xdf *.dup *.cmd";
  format_hash["x68000"]          = "*.dim *.m3u";
  format_hash["zmachine"]        = "*.dat *.z1 *.z2 *.z3 *.z4 *.z5 *.z6 *.z7 *.z8";
  format_hash["zx81"]            = "*.p *.tzx *.t81";
  format_hash["zxspectrum"]      = "*.sna *.szx *.z80 *.tap *.tzx *.gz *.udi *.mgt *.img *.trd *.scl *.dsk";

  return formats.append(format_hash[platform]);
}

// If user provides no scraping source with '-s' this sets the default for the platform
QString Platform::getDefaultScraper(QString platform)
{
  return "cache";
}

// This contains all known platform aliases as listed on each of the scraping source sites
QStringList Platform::getAliases(QString platform)
{
  QStringList aliases;
  // Platform name itself is always appended as the first alias
  aliases.append(platform);

  // If you don't find the platform listed below, it's probably because the needed alias is
  // the same as the platform name and has already been appended above.
  if(platform == "3ds") {
    aliases.append("nintendo 3ds");
  } else if (platform == "advision") {
    aliases.append("adventure Vision");
    aliases.append("entex adventure Vision");
  } else if(platform == "amiga") {
    aliases.append("amiga (aga)");
    aliases.append("amiga cdtv");
    aliases.append("amiga cd32");
    aliases.append("amiga cd32 (hack)");
    aliases.append("amiga cd");
    aliases.append("amigacd32");
    aliases.append("amigacdtv");
  } else if(platform == "amigacd32") {
    aliases.append("amiga cd32");
    aliases.append("amiga cd32 (hack)");
    aliases.append("amiga cd");
  } else if(platform == "amigacdtv") {
    aliases.append("amiga cdtv");
  } else if(platform == "amstradcpc") {
    aliases.append("amstrad cpc");
    aliases.append("cpc");
  } else if(platform == "apple2") {
    aliases.append("apple ii");
  } else if(platform == "arcade") {
    aliases.append("neo geo");
    aliases.append("neo-geo");
    aliases.append("neo geo cd");
    aliases.append("neo-geo cd");
    aliases.append("neo-geo mvs");
    aliases.append("capcom play system");
    aliases.append("capcom play system 2");
    aliases.append("capcom play system 3");
    aliases.append("another arcade emulator");
    aliases.append("cave");
    aliases.append("daphne");
    aliases.append("atomiswave");
    aliases.append("model 2");
    aliases.append("model 3");
    aliases.append("naomi");
    aliases.append("sega st-v");
    aliases.append("mame");
    aliases.append("type x");
    aliases.append("sega classics");
    aliases.append("irem classics");
    aliases.append("seta");
    aliases.append("midway classics");
    aliases.append("capcom classics");
    aliases.append("eighting / raizing");
    aliases.append("tecmo");
    aliases.append("snk classics");
    aliases.append("namco classics");
    aliases.append("namco system 22");
    aliases.append("taito classics");
    aliases.append("konami classics");
    aliases.append("jaleco");
    aliases.append("atari classics");
    aliases.append("nintendo classics");
    aliases.append("data east classics");
    aliases.append("nmk");
    aliases.append("sammy classics");
    aliases.append("exidy");
    aliases.append("acclaim");
    aliases.append("psikyo");
    aliases.append("non jeu");
    aliases.append("technos");
    aliases.append("american laser games");
    aliases.append("dynax");
    aliases.append("kaneko");
    aliases.append("video system co.");
    aliases.append("igs");
    aliases.append("comad");
    aliases.append("amcoe");
    aliases.append("century electronics");
    aliases.append("nichibutsu");
    aliases.append("visco");
    aliases.append("alpha denshi co.");
    aliases.append("coleco");
    aliases.append("playchoice");
    aliases.append("atlus");
    aliases.append("banpresto");
    aliases.append("semicom");
    aliases.append("universal");
    aliases.append("mitchell");
    aliases.append("seibu kaihatsu");
    aliases.append("toaplan");
    aliases.append("cinematronics");
    aliases.append("incredible technologies");
    aliases.append("gaelco");
    aliases.append("mega-tech");
    aliases.append("mega-play");
  } else if(platform == "arcadia") {
    aliases.append("arcadia 2001");
    aliases.append("emerson arcadia 2001");
  } else if(platform == "astrocade") {
    aliases.append("astrocde");
    aliases.append("bally astrocade");
  } else if(platform == "atari800") {
    aliases.append("atari 800");
    aliases.append("atari 8-bit");
    aliases.append("atari 5200");
  } else if(platform == "atari2600") {
    aliases.append("atari 2600");
  } else if(platform == "atari5200") {
    aliases.append("atari 5200");
  } else if(platform == "atari7800") {
    aliases.append("atari 7800");
  } else if(platform == "atarist") {
    aliases.append("atari st");
    aliases.append("atari st/ste");
  } else if(platform == "atarixegs") {
    aliases.append("atari xegs");
  } else if(platform == "atarijaguar") {
    aliases.append("atari jaguar");
    aliases.append("jaguar");
  } else if(platform == "atarilynx") {
    aliases.append("atari lynx");
    aliases.append("lynx");
  } else if(platform == "c16") {
    aliases.append("plus/4");
    aliases.append("commodore plus/4");
    aliases.append("commodore 16");
    aliases.append("commodore 16, plus/4");
  } else if(platform == "c64") {
    aliases.append("commodore 64");
    aliases.append("commodore c64/128");
  } else if(platform == "c128") {
    aliases.append("commodore 128");
    aliases.append("commodore 64");
    aliases.append("commodore c64/128");
  } else if(platform == "cd32") {
    aliases.append("amiga cd32");
    aliases.append("amiga cd32 (hack)");
    aliases.append("amigacd32");
  } else if(platform == "channelf") {
    aliases.append("channel f");
  } else if(platform == "cdtv") {
    aliases.append("amiga cdtv");
  } else if(platform == "coco") {
    aliases.append("trs-80 color computer");
    aliases.append("trs-80 coco");
  } else if(platform == "coleco") {
    aliases.append("colecovision");
  } else if(platform == "daphne") {
    aliases.append("pioneer laseractive");
    aliases.append("laseractive");
    aliases.append("american laser games");
  } else if(platform == "dragon32") {
    aliases.append("dragon 32/64");
  } else if(platform == "dreamcast") {
    aliases.append("sega dreamcast");
  } else if(platform == "electron") {
    aliases.append("acorn electron");
  } else if(platform == "fba") {
    aliases.append("arcade");
    aliases.append("neo geo");
    aliases.append("neo-geo");
    aliases.append("neo geo cd");
    aliases.append("neo-geo cd");
    aliases.append("neo-geo mvs");
    aliases.append("capcom play system");
    aliases.append("capcom play system 2");
    aliases.append("capcom play system 3");
    aliases.append("another arcade emulator");
    aliases.append("cave");
    aliases.append("daphne");
    aliases.append("atomiswave");
    aliases.append("model 2");
    aliases.append("model 3");
    aliases.append("naomi");
    aliases.append("sega st-v");
    aliases.append("mame");
    aliases.append("type x");
    aliases.append("sega classics");
    aliases.append("irem classics");
    aliases.append("seta");
    aliases.append("midway classics");
    aliases.append("capcom classics");
    aliases.append("eighting / raizing");
    aliases.append("tecmo");
    aliases.append("snk classics");
    aliases.append("namco classics");
    aliases.append("namco system 22");
    aliases.append("taito classics");
    aliases.append("konami classics");
    aliases.append("jaleco");
    aliases.append("atari classics");
    aliases.append("nintendo classics");
    aliases.append("data east classics");
    aliases.append("nmk");
    aliases.append("sammy classics");
    aliases.append("exidy");
    aliases.append("acclaim");
    aliases.append("psikyo");
    aliases.append("non jeu");
    aliases.append("technos");
    aliases.append("american laser games");
    aliases.append("dynax");
    aliases.append("kaneko");
    aliases.append("video system co.");
    aliases.append("igs");
    aliases.append("comad");
    aliases.append("amcoe");
    aliases.append("century electronics");
    aliases.append("nichibutsu");
    aliases.append("visco");
    aliases.append("alpha denshi co.");
    aliases.append("coleco");
    aliases.append("playchoice");
    aliases.append("atlus");
    aliases.append("banpresto");
    aliases.append("semicom");
    aliases.append("universal");
    aliases.append("mitchell");
    aliases.append("seibu kaihatsu");
    aliases.append("toaplan");
    aliases.append("cinematronics");
    aliases.append("incredible technologies");
    aliases.append("gaelco");
    aliases.append("mega-tech");
    aliases.append("mega-play");
  } else if(platform == "fds") {
    aliases.append("famicom disk system");
    aliases.append("family computer disk system");
    aliases.append("famiri konpyuta disuku shisutemu");
    aliases.append("nintendo entertainment system (nes)");
    aliases.append("nintendo");
  } else if(platform == "gameandwatch") {
    aliases.append("game & watch");
  } else if(platform == "gamegear") {
    aliases.append("sega game gear");
    aliases.append("game gear");
  } else if(platform == "gamepock") {
    aliases.append("epoch game pocket computer");
    aliases.append("egpc");
  } else if(platform == "gb") {
    aliases.append("nintendo game boy");
    aliases.append("game boy");
  } else if(platform == "gba") {
    aliases.append("nintendo game boy advance");
    aliases.append("game boy advance");
  } else if(platform == "gbc") {
    aliases.append("nintendo game boy color");
    aliases.append("game boy color");
    // Workaround: ScreenScraper sometimes returns gbc results with gb platform applied
    // This might bite me in the ass if other modules now return gb results for gbc games...
    aliases.append("game boy");
  } else if(platform == "gc") {
    aliases.append("gamecube");
    aliases.append("nintendo gamecube");
  } else if(platform == "genesis") {
    aliases.append("megadrive");
    aliases.append("sega genesis");
    aliases.append("mega drive");
    aliases.append("sega mega drive");
    aliases.append("sega mega drive/genesis");
  } else if(platform == "gx4000") {
    aliases.append("amstrad gx4000");
    aliases.append("gx-4000");
    aliases.append("gx 4000");
  } else if(platform == "mame-advmame") {
    aliases.append("arcade");
    aliases.append("neo geo");
    aliases.append("neo-geo");
    aliases.append("neo geo cd");
    aliases.append("neo-geo cd");
    aliases.append("neo-geo mvs");
    aliases.append("capcom play system");
    aliases.append("capcom play system 2");
    aliases.append("capcom play system 3");
    aliases.append("another arcade emulator");
    aliases.append("cave");
    aliases.append("daphne");
    aliases.append("atomiswave");
    aliases.append("model 2");
    aliases.append("model 3");
    aliases.append("naomi");
    aliases.append("sega st-v");
    aliases.append("mame");
    aliases.append("type x");
    aliases.append("sega classics");
    aliases.append("irem classics");
    aliases.append("seta");
    aliases.append("midway classics");
    aliases.append("capcom classics");
    aliases.append("eighting / raizing");
    aliases.append("tecmo");
    aliases.append("snk classics");
    aliases.append("namco classics");
    aliases.append("namco system 22");
    aliases.append("taito classics");
    aliases.append("konami classics");
    aliases.append("jaleco");
    aliases.append("atari classics");
    aliases.append("nintendo classics");
    aliases.append("data east classics");
    aliases.append("nmk");
    aliases.append("sammy classics");
    aliases.append("exidy");
    aliases.append("acclaim");
    aliases.append("psikyo");
    aliases.append("non jeu");
    aliases.append("technos");
    aliases.append("american laser games");
    aliases.append("dynax");
    aliases.append("kaneko");
    aliases.append("video system co.");
    aliases.append("igs");
    aliases.append("comad");
    aliases.append("amcoe");
    aliases.append("century electronics");
    aliases.append("nichibutsu");
    aliases.append("visco");
    aliases.append("alpha denshi co.");
    aliases.append("coleco");
    aliases.append("playchoice");
    aliases.append("atlus");
    aliases.append("banpresto");
    aliases.append("semicom");
    aliases.append("universal");
    aliases.append("mitchell");
    aliases.append("seibu kaihatsu");
    aliases.append("toaplan");
    aliases.append("cinematronics");
    aliases.append("incredible technologies");
    aliases.append("gaelco");
    aliases.append("mega-tech");
    aliases.append("mega-play");
  } else if(platform == "mame-libretro") {
    aliases.append("arcade");
    aliases.append("neo geo");
    aliases.append("neo-geo");
    aliases.append("neo geo cd");
    aliases.append("neo-geo cd");
    aliases.append("neo-geo mvs");
    aliases.append("capcom play system");
    aliases.append("capcom play system 2");
    aliases.append("capcom play system 3");
    aliases.append("another arcade emulator");
    aliases.append("cave");
    aliases.append("daphne");
    aliases.append("atomiswave");
    aliases.append("model 2");
    aliases.append("model 3");
    aliases.append("naomi");
    aliases.append("sega st-v");
    aliases.append("mame");
    aliases.append("type x");
    aliases.append("sega classics");
    aliases.append("irem classics");
    aliases.append("seta");
    aliases.append("midway classics");
    aliases.append("capcom classics");
    aliases.append("eighting / raizing");
    aliases.append("tecmo");
    aliases.append("snk classics");
    aliases.append("namco classics");
    aliases.append("namco system 22");
    aliases.append("taito classics");
    aliases.append("konami classics");
    aliases.append("jaleco");
    aliases.append("atari classics");
    aliases.append("nintendo classics");
    aliases.append("data east classics");
    aliases.append("nmk");
    aliases.append("sammy classics");
    aliases.append("exidy");
    aliases.append("acclaim");
    aliases.append("psikyo");
    aliases.append("non jeu");
    aliases.append("technos");
    aliases.append("american laser games");
    aliases.append("dynax");
    aliases.append("kaneko");
    aliases.append("video system co.");
    aliases.append("igs");
    aliases.append("comad");
    aliases.append("amcoe");
    aliases.append("century electronics");
    aliases.append("nichibutsu");
    aliases.append("visco");
    aliases.append("alpha denshi co.");
    aliases.append("coleco");
    aliases.append("playchoice");
    aliases.append("atlus");
    aliases.append("banpresto");
    aliases.append("semicom");
    aliases.append("universal");
    aliases.append("mitchell");
    aliases.append("seibu kaihatsu");
    aliases.append("toaplan");
    aliases.append("cinematronics");
    aliases.append("incredible technologies");
    aliases.append("gaelco");
    aliases.append("mega-tech");
    aliases.append("mega-play");
  } else if(platform == "mame-mame4all") {
    aliases.append("arcade");
    aliases.append("neo geo");
    aliases.append("neo-geo");
    aliases.append("neo geo cd");
    aliases.append("neo-geo cd");
    aliases.append("neo-geo mvs");
    aliases.append("capcom play system");
    aliases.append("capcom play system 2");
    aliases.append("capcom play system 3");
    aliases.append("another arcade emulator");
    aliases.append("cave");
    aliases.append("daphne");
    aliases.append("atomiswave");
    aliases.append("model 2");
    aliases.append("model 3");
    aliases.append("naomi");
    aliases.append("sega st-v");
    aliases.append("mame");
    aliases.append("type x");
    aliases.append("sega classics");
    aliases.append("irem classics");
    aliases.append("seta");
    aliases.append("midway classics");
    aliases.append("capcom classics");
    aliases.append("eighting / raizing");
    aliases.append("tecmo");
    aliases.append("snk classics");
    aliases.append("namco classics");
    aliases.append("namco system 22");
    aliases.append("taito classics");
    aliases.append("konami classics");
    aliases.append("jaleco");
    aliases.append("atari classics");
    aliases.append("nintendo classics");
    aliases.append("data east classics");
    aliases.append("nmk");
    aliases.append("sammy classics");
    aliases.append("exidy");
    aliases.append("acclaim");
    aliases.append("psikyo");
    aliases.append("non jeu");
    aliases.append("technos");
    aliases.append("american laser games");
    aliases.append("dynax");
    aliases.append("kaneko");
    aliases.append("video system co.");
    aliases.append("igs");
    aliases.append("comad");
    aliases.append("amcoe");
    aliases.append("century electronics");
    aliases.append("nichibutsu");
    aliases.append("visco");
    aliases.append("alpha denshi co.");
    aliases.append("coleco");
    aliases.append("playchoice");
    aliases.append("atlus");
    aliases.append("banpresto");
    aliases.append("semicom");
    aliases.append("universal");
    aliases.append("mitchell");
    aliases.append("seibu kaihatsu");
    aliases.append("toaplan");
    aliases.append("cinematronics");
    aliases.append("incredible technologies");
    aliases.append("gaelco");
    aliases.append("mega-tech");
    aliases.append("mega-play");
  } else if(platform == "mastersystem") {
    aliases.append("sega master system");
    aliases.append("master system");
  } else if(platform == "megacd") {
    aliases.append("segacd");
    aliases.append("sega cd");
    aliases.append("mega-cd");
  } else if(platform == "megadrive") {
    aliases.append("genesis");
    aliases.append("sega mega drive");
    aliases.append("sega mega drive/genesis");
    aliases.append("mega drive");
  } else if(platform == "megaduck") {
    aliases.append("mega duck");
    aliases.append("cougarboy");
    aliases.append("cougar boy");
  } else if(platform == "msx") {
    aliases.append("msx2");
    aliases.append("msx2+");
    aliases.append("msx r turbo");
  } else if(platform == "msx2") {
    aliases.append("msx2");
    aliases.append("msx2+");
  } else if(platform == "n64") {
    aliases.append("nintendo 64");
  } else if(platform == "nds") {
    aliases.append("nintendo ds");
  } else if(platform == "neogeo") {
    aliases.append("neo-geo");
    aliases.append("neo geo");
    aliases.append("neo geo aes");
    aliases.append("neo geo mvs");
    aliases.append("neo geo cd");
    aliases.append("neo-geo cd");
    aliases.append("arcade");
  } else if(platform == "neogeocd") {
    aliases.append("neo-geo");
    aliases.append("neo geo");
    aliases.append("neo geo aes");
    aliases.append("neo geo mvs");
    aliases.append("neo geo cd");
    aliases.append("neo-geo cd");
    aliases.append("arcade");
  } else if(platform == "nes") {
    aliases.append("nintendo entertainment system (nes)");
    aliases.append("nintendo");
    aliases.append("nintendo power");
  } else if(platform == "ngp") {
    aliases.append("neo geo pocket");
    aliases.append("neo-geo pocket");
  } else if(platform == "ngpc") {
    aliases.append("neo geo pocket color");
    aliases.append("neo-geo pocket color");
  } else if(platform == "oric") {
    aliases.append("oric 1 / atmos");
  } else if(platform == "pc") {
    aliases.append("pc dos");
    aliases.append("pc win3.xx");
    aliases.append("dos");
    aliases.append("windows");
    aliases.append("windows apps");
    aliases.append("pc (microsoft windows)");
    aliases.append("steamos");
  } else if(platform == "pc88") {
    aliases.append("pc-88");
    aliases.append("pc-8801");
  } else if(platform == "pc98") {
    aliases.append("pc-98");
    aliases.append("nec pc-9801");
  } else if(platform == "pcfx") {
    aliases.append("pc-fx");
  } else if(platform == "pcengine") {
    aliases.append("turbografx 16");
    aliases.append("turbografx cd");
    aliases.append("turbografx-16");
    aliases.append("turbografx-16/pc engine");
    aliases.append("turbografx-16/pc engine cd");
    aliases.append("pc engine");
    aliases.append("pc engine cd-rom");
    aliases.append("pc engine supergrafx");
  } else if(platform == "pcenginecd") {
    aliases.append("turbografx cd");
    aliases.append("turbografx-16/pc engine cd");
    aliases.append("pc engine cd-rom");
    aliases.append("pc engine supergrafx");
  } else if(platform == "pokemini") {
    aliases.append("nintendo pokémon mini");
    aliases.append("pokémon mini");
  } else if(platform == "ports") {
    aliases.append("pc dos");
    aliases.append("pc win3.xx");
    aliases.append("dos");
    aliases.append("windows");
    aliases.append("pc (microsoft windows)");
  } else if(platform == "psx") {
    aliases.append("sony playstation");
    aliases.append("playstation");
  } else if(platform == "ps2") {
    aliases.append("playstation 2");
    aliases.append("sony playstation 2");
  } else if(platform == "psp") {
    aliases.append("sony playstation portable");
    aliases.append("playstation portable");
  } else if(platform == "saturn") {
    aliases.append("sega saturn");
  } else if(platform == "scummvm") {
    aliases.append("pc dos");
    aliases.append("pc win3.xx");
    aliases.append("pc");
    aliases.append("amiga");
    aliases.append("amigacd32");
    aliases.append("amigacdtv");
    aliases.append("amiga cd32");
    aliases.append("dos");
    aliases.append("cd32");
    aliases.append("pc (microsoft windows)");
    aliases.append("residualvm");
    aliases.append("windows");
    aliases.append("windows apps");
  } else if(platform == "sega32x") {
    aliases.append("sega 32x");
    aliases.append("megadrive 32x");
  } else if(platform == "segacd") {
    aliases.append("megacd");
    aliases.append("sega cd");
    aliases.append("mega-cd");
  } else if(platform == "sg-1000") {
    aliases.append("sega sg-1000");
  } else if(platform == "sgb") {
    aliases.append("super game boy");
  } else if(platform == "snes") {
    aliases.append("super nintendo (snes)");
    aliases.append("super nintendo entertainment system (snes)");
    aliases.append("super nintendo");
    aliases.append("super famicom");
    // The following are for screenscraper, but the platform check is currently disabled for
    // that module, so they don't really do anything.
    aliases.append("nintendo power");
    aliases.append("satellaview");
    aliases.append("sufami turbo");
    aliases.append("snes - super mario world hacks");
    aliases.append("super nintendo msu-1");
  } else if(platform == "snesmsu1") {
    aliases.append("super nintendo msu-1");
  } else if(platform == "sufami") {
    aliases.append("sufamiturbo");
    aliases.append("sufami turbo");
  } else if(platform == "steam") {
    aliases.append("pc dos");
    aliases.append("pc win3.xx");
    aliases.append("dos");
    aliases.append("windows");
    aliases.append("windows apps");
    aliases.append("pc (microsoft windows)");
    aliases.append("steamos");
    // Adding these consoles because 'thegamesdb' often only return these instead of PC versions
    aliases.append("microsoft xbox one");
    aliases.append("sony playstation 4");
  } else if(platform == "thomson") {
    aliases.append("m5");
    aliases.append("t07");
  } else if(platform == "ti99") {
    aliases.append("ti-99/4a");
    aliases.append("texas instruments ti-99");
    aliases.append("texas instruments ti-99/4a");
  } else if(platform == "trs-80") {
    aliases.append("trs-80 color computer");
  } else if(platform == "vic20") {
    aliases.append("commodore vic-20");
    aliases.append("vic-20");
  } else if(platform == "videopac") {
    aliases.append("odyssey 2");
    aliases.append("magnavox odyssey 2");
    aliases.append("videopac g7000");
    aliases.append("philips videopac g7000");
    aliases.append("videopac+ g7400");
    aliases.append("magnavox odyssey²");
  } else if(platform == "virtualboy") {
    aliases.append("nintendo virtual boy");
    aliases.append("virtual boy");
  } else if(platform == "wii") {
    aliases.append("nintendo wii");
    aliases.append("wiiware");
  } else if(platform == "wiiu") {
    aliases.append("nintendo wii u");
    aliases.append("wii u");
    aliases.append("wiiware");
  } else if(platform == "wonderswancolor") {
    aliases.append("wonderswan color");
  } else if(platform == "x68000") {
    aliases.append("sharp x68000");
  } else if(platform == "zmachine") {
    aliases.append("x1");
  } else if(platform == "sharp x1") {
    aliases.append("z-machine");
  } else if(platform == "zxspectrum") {
    aliases.append("sinclair zx spectrum");
    aliases.append("zx spectrum");
  }
  return aliases;
}

// --- Console colors ---
// Black        0;30     Dark Gray     1;30
// Red          0;31     Light Red     1;31
// Green        0;32     Light Green   1;32
// Brown/Orange 0;33     Yellow        1;33
// Blue         0;34     Light Blue    1;34
// Purple       0;35     Light Purple  1;35
// Cyan         0;36     Light Cyan    1;36
// Light Gray   0;37     White         1;37
