import pyautogui as pag

def_interval = 0.1

pag.keyDown("win")
pag.press("d")
pag.keyUp("win")
pag.write("google",def_interval)
pag.press("enter")
pag.write("Eu gosto de tu luizita, so finjo mesmo que nao",def_interval)
pag.keyDown("ctrl")
pag.press("a")
pag.keyUp("ctrl")
pag.press("delete")
pag.write("Olha se voce nao me ama",def_interval)




# position(x=486, y=139)