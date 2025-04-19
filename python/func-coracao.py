class Coração(Scene):
    def construct(self):
        plano = NumberPlane(x_range=(-3,3), y_range=(-2,2)).scale(1.5)
        graf = plano.plot_implicit_curve(lambda x,y: (x**2+y**2-1)**3-x**2*y**3).set_color(RED).scale(1.5)

        texto = Text("tinhamu <3", color=RED)
        texto2 = MathTex("(x^2+y^2-1)^3-x^2y^3=0", color=RED).next_to(texto, DOWN)
        self.play(Create(plano))
        self.play(Create(graf), run_time=2)
        self.play(FadeOut(VGroup(plano, graf)))
        self.play(Create(texto), Create(texto2))
        self.wait(3)