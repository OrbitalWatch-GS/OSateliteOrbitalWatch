# OrbitalWatch - Sistema Embarcado para Monitoramento de Detritos Espaciais 🛰️

## 📝 Descrição do Projeto
O **OrbitalWatch** é uma solução de engenharia de software embarcada voltada para a resiliência e sustentabilidade das infraestruturas espaciais na Terra e na órbita baixa (LEO). Alinhado diretamente com os Objetivos de Desenvolvimento Sustentável da ONU, especificamente o **ODS 9 (Indústria, Inovação e Infraestrutura)** e o **ODS 11 (Cidades e Comunidades Sustentáveis)**, o projeto simula o sistema computacional de bordo (*Edge Computing*) de um nanossatélite. Ele monitora a aproximação de lixo espacial e detritos orbitais em tempo real, mitigando os riscos de colisões catastróficas que ameaçam os sistemas globais de comunicação, GPS e previsão do tempo.

## 🎯 Objetivo da Solução
Proteger os satélites ativos contra colisões com os mais de 27.000 fragmentos de detritos rastreados no espaço. O sistema fornece telemetria contínua, alertas visuais/sonoros graduais para os operadores e uma interface de acionamento imediato para execução de manobras de desvio orbital evasivas manuais e automatizadas.

## 🛠️ Componentes Utilizados
Para a construção do protótipo no ecossistema simulado, foram utilizados os seguintes componentes eletrônicos:
* **1x Microcontrolador Arduino UNO** (Processador central de bordo)
* **1x Sensor de Distância Ultrassônico HC-SR04** (Simulador do Radar de Proximidade Espacial)
* **1x Display LCD 16x2 com Módulo de Comunicação I2C** (Painel de Telemetria Visual)
* **1x LED Verde** (Indicador de Órbita Segura)
* **1x LED Amarelo** (Indicador de Alerta de Aproximação)
* **1x LED Vermelho** (Indicador de Risco Crítico de Colisão)
* **3x Resistores de 220 Ω** (Proteção de corrente dos LEDs)
* **1x Resistor de 10 kΩ** (Configuração Pull-down do botão de desvio para evitar pino flutuante)
* **1x Push Button / Botão de Pressão** (Atuador de Manobra de Emergência)
* **1x Elemento Piezoelétrico / Buzzer** (Alarme Sonoro de Proximidade)
* **1x Matriz de Contatos / Protoboard Pequena** (Barramento para distribuição de sinais)
* **Fios de Conexão (Jumpers)** coloridos para organização visual do circuito

## ⚙️ Explicação do Funcionamento
O software de controle embarcado monitora constantemente os dados do sensor ultrassônico e divide o status operacional em uma máquina de 4 estados principais baseado na distância do objeto rastreado:

1. **ZONA SEGURA (Distância > 150 cm):** O satélite opera normalmente. O LED Verde mantém-se aceso, o buzzer fica em silêncio e o painel LCD exibe `STATUS: SEGURO` e `Orbita Limpa`.
2. **ZONA DE ALERTA (Entre 50 cm e 150 cm):** Um detrito entrou no raio de monitoramento. O LED Verde desliga e o LED Amarelo acende. O buzzer começa a emitir bips pulsantes lentos e o LCD atualiza dinamicamente a distância atual do perigo com precisão decimal (`ALERTA: DETRITO / Prox: XX.Xcm`).
3. **ZONA CRÍTICA (Distância < 50 cm):** Risco de colisão iminente. O LED Vermelho acende fixo, o buzzer dispara um alarme agudo contínuo e o LCD exige intervenção humana imediata exibindo alternadamente `PERIGO: COLISAO` e `APERTE P/ DESVIO`.
4. **MECANISMO DE MANOBRA EVASIVA:** Se o operador pressionar o *Push Button* enquanto o sistema estiver na zona crítica, o circuito valida a leitura de Pull-Down no pino digital. O alarme cessa instantaneamente, todos os LEDs acendem como confirmação e o LCD exibe a mensagem de sucesso `MANOBRA MANUAL / EXECUTADA: OK!` por 3 segundos. Após o processamento do desvio, o sistema limpa as variáveis e retoma o monitoramento seguro de órbita.

## 🔌 Estrutura do Circuito e Pinagem
As conexões elétricas foram mapeadas e padronizadas seguindo a arquitetura abaixo:
* **Sensor Ultrassônico (HC-SR04):** VCC -> 5V | GND -> GND | Trig -> **Pino 12** | Echo -> **Pino 11**
* **Display LCD I2C:** VCC -> 5V | GND -> GND | SDA -> **Pino A4** | SCL -> **Pino A5**
* **LEDs (Sinalização):** Verde -> **Pino 2** | Amarelo -> **Pino 3** | Vermelho -> **Pino 4** (todos utilizando os resistores de 220 Ω em série nos Anodos)
* **Buzzer (Som):** Terminal Positivo -> **Pino 5** | Terminal Negativo -> GND
* **Push Button (Entrada):** Terminal de Sinal + Resistor Pull-Down 10k -> **Pino 7** | Terminal Oposto -> 5V

## 🚀 Instruções de Execução e Testes
1. Acesse o repositório público do projeto ou abra o ambiente de simulação através do link disponibilizado.
2. Clique no botão **"Iniciar Simulação"** no topo superior direito do ambiente.
3. Observe a inicialização do sistema com o boot: `OrbitalWatch v1` e `Sistemas: ONLINE` no LCD.
4. Para simular a órbita do detrito, dê um clique com o mouse em cima da peça azul do **Sensor Ultrassônico**. Um cone verde com uma esfera de teste irá aparecer.
5. Arraste a esfera para os quadrantes de distância (Distante, Médio e Próximo) e observe os LEDs trocarem de cor, o buzzer alterar o ritmo do som e as mensagens mudarem dinamicamente no LCD.
6. Aproxime a esfera a menos de 50 cm (ativando a tela vermelha de perigo) e dê um clique no **Push Button preto** localizado no centro da placa de ensaio para validar o reset de manobra bem-sucedida.

https://github.com/user-attachments/assets/90801f2a-d07b-463b-9b6f-5c956806f119

---

## 🔗 Link da Simulação Online
* **Link do Projeto no Tinkercad:** [https://www.tinkercad.com/things/cgrefpPEOuO-satelite-orbitalwatch?sharecode=0FT-xgXW0i7X-JMe0o5j88X16gAK3pLUla5jJYOquYA](https://www.tinkercad.com/things/cgrefpPEOuO-satelite-orbitalwatch?sharecode=0FT-xgXW0i7X-JMe0o5j88X16gAK3pLUla5jJYOquYA)

## 👥 Integrantes do Grupo
* **João Pedro Maschion da Cruz Sá** - RM: 570509
* **Gustavo Rezende Louro** - RM: 570708
* **João Pedro Lagonegro Bosco e Silva** - RM: 569444
* **Lucas Henrique Alves da Silva** - RM: 572216
