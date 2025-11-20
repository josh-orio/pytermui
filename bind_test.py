import sys
sys.path.append("build/bindings")

import pytermui

t = pytermui.Strings(["Ketchup", "Mustard", "BBQ"])

m = pytermui.Menu("Sauce", t, 1)
m.show()

pytermui.Menu("Sauce", t, 0).show()
