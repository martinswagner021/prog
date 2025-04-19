table = {
    alanninha="meu amorzinho ♥",
    idade=20;
    "estagio",
    "aulas de ingles",
    "controle e qualidade de alim",
    "farmaco cardiovascular e quimioterapia",
    "microbiologia",
    "top esp em analises clinicas",
    "prod e controle de med ii",
    "bioquimica",
    "biofarmacia"
}


print("ela eh: " .. table.alanninha)
print("ela faz as seguintes coisas:")
for i=1,9 do
    print(table[i])
end