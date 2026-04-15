import pytermui

t = pytermui.strings(["Ketchup", "Mustard", "BBQ"])

title = pytermui.string("Sauce")

m = pytermui.Menu(title, t, 1)
m.show()

pytermui.Menu("Sauce", t, 0).show()

pytermui.Menu("Sauce", t).show() # optional arg supported
