import pyautogui as pag

def_interval = 0.1

pag.keyDown("win")
pag.press("d")
pag.keyUp("win")
pag.write("google",def_interval)
pag.press("enter")
pag.write("Random text",def_interval)
pag.keyDown("ctrl")
pag.press("a")
pag.keyUp("ctrl")
pag.press("delete")
pag.write("hehe",def_interval)




# position(x=486, y=139)