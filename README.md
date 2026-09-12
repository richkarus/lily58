# lily58

Personal [QMK External Userspace](https://docs.qmk.fm/newbs_external_userspace)
for a Lily58 (rev1), converted from its stock Pro Micro to two RP2040
controllers (`promicro_to_rp2040_ce` converter), running VIA.

## Setup

Requires a local clone of [qmk_firmware](https://github.com/qmk/qmk_firmware)
with the CLI set up (see the [newbs guide](https://docs.qmk.fm/newbs)).

```sh
git clone https://github.com/richkarus/lily58.git
qmk config user.overlay_dir="$(realpath lily58)"
```

## Building

```sh
qmk compile -kb lily58/rev1 -km via -e CONVERT_TO=rp2040_ce
```

or build every registered target in `qmk.json` at once:

```sh
qmk userspace-compile
```

## Flashing

Both halves use RP2040 controllers, so both take the same `.uf2`:

1. Hold BOOTSEL / double-tap reset to drop a half into bootloader mode (shows
   up as the `RPI-RP2` mass storage drive).
2. Copy `lily58_rev1_via_rp2040_ce.uf2` onto it.
3. Repeat for the other half.

If a keymap layout change doesn't seem to take effect after flashing, the
board's persisted VIA/EEPROM data may be stale. This keymap has Bootmagic
Lite enabled: hold the top-left key (`Esc`) while plugging in the master
(USB) half to reset it.

## VIA

`keyboards/lily58/keymaps/via/lily58_rev1_via.json` is a hand-generated VIA
"draft definition" (VIA doesn't otherwise recognize this board/converter
combo automatically). In the VIA app: Settings -> enable "Show Design tab" ->
Design tab -> Load Draft Definition -> select that file.

## Layout

- `_BASE` / `_LOWER` (hold `D`) / `_RAISE` (hold `F`) - ported from the
  Voyager's layer-tap setup.
- Home-row mods on `J`/`K`/`L` (GUI/Ctrl/Alt), same as the Voyager.
- `CHORDAL_HOLD` + `TAPPING_TERM 200` tuned so the home-row mods behave like
  they did on the Voyager (same-hand roll = hold, opposite-hand roll = tap).
