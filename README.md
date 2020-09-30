# Projeto-EEN251
#Projeto T1
Repositório do Projeto da Aula EEN251-Microcontroladores e Sistemas Embarcados

@Gubeera Gustavo Villela Rubia (CM) - 17.01736-0

@LucasLibra Lucas Negresiolo Libório (CM) - 17.01165-5

@MurLeal Murilo Leal Luz Barros (EN) - 17.04313-0

Ideias de Projetos:

1. Robô seguidor de linha que utiliza geometria analítica

2. Robô aspirador de pó

3. Controle de Iluminação Precisa de uma Lâmpada

4. Sistema de Liberação de Catracas que utilizam RFID

5. Veículo robótico de combate a incêndio.

Projeto Escolhido
Robo Higienizador de ambientes controlado por bluetooth
O robo é controlado pelo usuario sendo possível o controle da direção e acionamento de borrifo de liquido higienizante e um
alerta de falta carga do borrifador.
---------------------------------------------------------------------------------------------------------------------------------------------------------

#Projeto T2
Repositório do Projeto da Aula EEN251-Microcontroladores e Sistemas Embarcados

@Gubeera Gustavo Villela Rubia (CM) - 17.01736-0

@LucasLibra Lucas Negresiolo Libório (CM) - 17.01165-5

@MurLeal Murilo Leal Luz Barros (EN) - 17.04313-0

Criar um simulador arcade com  raspberry pi, utilizando a plataforma retropie, e controlando através de botões externos atravez de mapeamento da GPIO.

Pra implementação do projeto nos utilizamos tambem a biblioteca GPIOnext %https://github.com/mholgatem/GPIOnext
- Primeiramente utilizamos um cartão SD para gravar o SO do retropie e realizamos as configurações iniciais e atualização dos pacotes pelo cmd com comandos do Ubuntu
- Após isso realizamos o clone da biblioteca e habilitamos o SSH do raspberry e executamos a biblioteca GPIONext
- Para configuração dos botões em suas respectivas GPIOs utilizamos o comando GPIO config e habilitamos as portas respectivas para cada botão, por exemplo a GPIO 23 seria respectivamente o botão "left button" do controle
- Iniciamos o emulation station,já contido no retropie, e configuramos como um joystick os botões seguindo o padrão de botões feito no passo anterior
- Obtemos a ROMs de alguns consoles suportados pelo retropie e colocamos em um pendrive usb já com as pastas anteriormente cridas para cada console
- Testamos alguns jogos para validar o conrole.



