# The Possumvibes Keymap: the QMK-specific overview

A featureset designed around holding keys down as little as possible, keeping finger use balanced across all layers, and reducing fast and/or repetitive thumb movement as much as possible. This layout leverages combos, home row mods, smart layers, one- and two-shot (*n*-shot, to be specific) mods, locking mods, and one-tap swappers to reduce the number of layer tap-holds needed. 

The layout itself is defined per keyboard, but the core 3x5+2 layout is defined in blocks of five keys using Drashna's wrappers approach. My comfortable range of motion on MX boards is two thumb keys per side, and I'm far more comfortable using thumbs for taps (including thumb-only combos) than holding thumbs. Nav, on my left home thumb, is my only thumb tap-hold, and all other layers are accessed via combo, direct toggle, or alpha LT.

### N-shot mods
These are an adaptation of the Callum oneshot mods that use array structure and leave the mod "sticky" for a specified *n* amount of keypresses (practically speaking, this means one-shot mods plus a two-shot Ctrl.) N-shots leverage mod bits rather than mod keycodes to allow for multi-mod n-shots (e.g., Gui+Ctrl). Like the Callum implementation, "ignore" and "cancel" keys are defined in separate functions. 

This implementation solves the issue of shifting extra characters when rolling present in the base Callum implementation. It also makes the ability to roll _into_ the mod customizable. When held for longer than TAPPING_TERM without another keypress, the mod will act as a normal held mod and release without queueing.

I currently use nshots on alpha as my thumb one-shot shift, in combos for ease of window management, and on my nav layer, which is accessible from any layer, for use on my non-alpha layers. I use a combination of home row mods, thumb shift, combos, and n-shots on a layer for my mods to allow me multiple ways of activating my most commonly used mods. 

Of note: if not using an n-shot on thumb in combination with smart layers for order-agnostic layer+mod activation, *use the default OSM for thumbshift instead*. 

### Smart Layers
Smart layers are, functionally, caps word but for your layer of choice, with cancel keys defined. I have NumMode and FuncMode, each of which allow me to keep typing numbers or f-keys respectively until I hit a cancel key. These are likewise born out of a passionate dislike of holding layer toggles or using thumbs for any kind of fast or repeated movement (*especially* involving holding layer toggles). These are very much inspired by the T-34 layout, linked in the code influences section.

Another neat feature of the smart layer implementation is the ability to make a "oneshot" layer that allows mods to be activated before or after the layer is toggled. I am leveraging this on my SYM layer, which uses shift overrides for a bunch of macros, and allows me to tap layer and mods in any order (eg, Symmode OS-Shift Paren gives the same result as OS-Shift Symmode Paren). This makes it a lot easier for me to leverage the layer without thumb-shift redirects.

### Combos
I use combos very heavily for punctuation and shortcuts. I have enter on the bottom row and tab, esc, and macros on the top row. Home row horizontal combos include cut-copy-paste; home row diagonal with outer thumb activate layer modes. Extra punctuation is primarily on home row, but there are a few characters on home and top as well. Mouse keys are on left hand vertical combos, and more layer access combos are on thumb keys (vertical combo with QWERTY B/N on flat boards, horizontal combo on boards with lowered thumb clusters). As I've reduced down to 34-35 keys, I've added more cross-row combos for things like CapsLock+Word and per-OS app finder. Recent changes emphasize reduced rolling and typo'd activations.

### Locking Mods
These are "locking" toggle-able mods with a defined cancel/continue key list. I use these on my nav layer, specifically for hands-off text editing in cases where I'd otherwise need to keep a mod held (e.g., to select text with Ctrl+Shift+arrow, I can tap into my nav layer, tap locking Ctrl and Shift, and then tap or hold the arrow as long as needed.) My usage of them is very narrow--anything besides the navigation keys (arrows, home, end) and the locking mods themselves will reset the toggled mods. I don't have to use these often, since I main modal editors, but boy howdy, when I need them, these are joint-savers for me.

### Swapper
Another Callum feature, modified to accept a reverse trigger and action. The modifier is released with the press or release of another non-swapper key (the releasing keypress is swallowed and does not get handled after cancelling the swapper). I am not currently using this feature, but it's very handy to have around. 


### Layout

The base layout that all my boards use can be found in [my keyboard layout README](https://github.com/possumvibes/keyboard-layout) (images are usually not quite up to date, but close enough to get the idea across).

### Navigating the userspace

 `./keymaps` folder holds json keymaps.

 `./features` folder holds my custom features.

 `./archive` folder holds the features and configurations I'm not currently using, but don't want to delete.

`./possumvibes.h` is the primary file imported into each keyboard's keymap and defines a few functions that `possumvibes.c` implements.

`./keycodes.h` holds all the enums, custom keycodes, and key aliases, while  `layout.h` holds the layer blocks of keycodes to be applied reusably per keymap.

`./combos.def` holds the combo definitions for the `gboards` implementation, and `combos.c` holds the functions for per-combo combo terms, the must-tap and must-hold configuration.
 
`./possumvibes.c` holds the `process_record_user` implementation and handles all the userspace-defined custom keycodes. It holds some additional customization for enabled features like caps word.

Last but not least, this readme has links to all my current board keymaps at the end so it's easier to see how these get used in practice.

### Code Influences (alphabetically and non-comprehensively)
- Callum's [userspace](https://github.com/qmk/qmk_firmware/tree/master/users/callum) - Oneshots, swappers
- Drashna's [userspace](https://github.com/qmk/qmk_firmware/tree/master/users/drashna) - Wrappers, layout override functions, and a whole lot more
- Jonas H's [T34 layout](https://www.jonashietala.se/blog/2021/06/03/the-t-34-keyboard-layout/) - Numword
- Manna-Harbour's [Miryoku layout](https://github.com/manna-harbour/miryoku) - The actual starting point of this layout, many iterations ago
- Patrick Getreuer's [QMK articles](https://getreuer.info/posts/keyboards/index.html) (aka How I Learned To Stop Worrying And Love Arrays)
- The Hands Down and Alt Keyboard Layouts Discord servers, for some hella cool alpha layouts and different ways of approaching layout balance at the layer and layout levels

### Possumvibes Keyboard Vault

CURRENTLY USING: Hypergarlic by David Philip Barr (Legally, this is a Cradio or a Sweep :D )

PREVIOUSLY USED:
- Osprette and Clog (34 keys; [Readme](../../keyboards/osprette/keymaps/possumvibes/readme.md)): Choc-spaced pinky cluster boards from [S'mores' Boards](https://www.smoresboards.com/). Uses this userspace keymap.
- Fissure (36-40 keys; [Readme](../../keyboards/fissure/keymaps/possumvibes/readme.md)): My current daily driver! A choc-spaced board with two keys in each 6th col for steno. Uses this userspace keymap.
- Kyria (38 keys; [Readme](../../keyboards/splitkb/kyria/keymaps/possumvibes/readme.md)): A 44-46 key MX split from [SplitKb](https://splitkb.com/). Uses this userspace keymap.
- and others!
