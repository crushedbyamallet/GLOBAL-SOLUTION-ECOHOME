# 🌱🏠 *ecohome:* sistema inteligente de monitoramento de consumo energético residencial

### **Introdução**
O **ecohome** uma solução de monitoramento de consumo de energia residencial que visa incentivar práticas sustentáveis e a economia de energia. 
Utilizando tecnologias IoT, a solução permite que os usuários acompanhem o consumo de diferentes eletrodomésticos em tempo real.

---

## **📐 Arquitetura do sistema**

O sistema EcoHome é composto pelos seguintes elementos:

### **Componentes e tecnologias**
- **Hardware**: Placa ESP32 como microcontrolador, responsável pela coleta e envio de dados.
- **Sensores virtuais**: Dados baseados em consumo realista de dispositivos como geladeira, ar-condicionado, micro-ondas, lâmpadas e TV.
- **Plataforma IoT**: **thinger.io**, para criar dashboards interativos e configurar os widgets de monitoramento.
- **Protocolo de comunicação**: IOTMP, nativo do Thinger.io, garantindo uma integração eficiente entre a ESP32 e o gateway.
- **Linguagem de programação**: C++
- **Ambiente de desenvolvimento**: (arduino IDE)

---

## **🚀 Funcionalidades**

1. **Monitoramento em "tempo real"**:
   - Dados individuais de consumo dos principais eletrodomésticos (em kWh/dia), apresentados em widgets do tipo *Gauge*.
   - Consumo total exibido em um gráfico de séries temporais.

2. **Alertas**:
   - Alertas de alto consumo acionados automaticamente quando o consumo total excede limites predefinidos.

3. **Recomendações de economia**:
   - Mensagens dinâmicas com sugestões para otimizar o uso de energia, baseadas nos dados coletados.

4. **Interface intuitiva**:
   - Dashboards configurados no **thinger.io**, incluindo widgets que exibem alertas, gráficos e consumo por dispositivo.

---


## **📊 Dashboard**

Os seguintes widgets foram configurados para o painel de controle:

| **Widget**             | **Descrição**                                                | **Tipo**              |
|-------------------------|------------------------------------------------------------|-----------------------|
| Projeto                 | Nome do projeto no topo do dashboard                       | Text/Value           |
| Consumo Total           | Gráfico de consumo consolidado em tempo real               | Time Series Chart    |
| Consumo Geladeira       | Consumo da geladeira em kWh/dia                             | Gauge                |
| Consumo Ar-Condicionado | Consumo do ar-condicionado em kWh/dia                       | Gauge                |
| Consumo TV              | Consumo da TV em kWh/dia                                    | Gauge                |
| Consumo Micro-ondas     | Consumo do micro-ondas em kWh/dia                           | Gauge                |
| Consumo Luz             | Consumo das lâmpadas em kWh/dia                             | Gauge                |
| Alertas                 | Indicador de alto consumo                                   | Led Indicator        |
| Mensagem Economia       | Recomendações automáticas para economia de energia          | Text/Value           |

**Intervalo de amostragem:** Todos os widgets estão configurados para atualizar a cada **10 segundos**.

![image](https://github.com/user-attachments/assets/238e7e78-f58d-4154-9e1e-8fcbf18d698b)


---

## **📜 Fontes e justificativas**

Os valores de consumo simulados dos eletrodomésticos foram baseados em padrões reais de uso obtidos de estudos sobre consumo elétrico residencial, além de dados de fabricantes de eletrodomésticos. 
Cada dispositivo foi configurado para representar um cenário típico de consumo:

- **Geladeira**: 1,2 kWh/dia (baseado em modelos padrão com eficiência energética A).
- **Ar-condicionado**: 5,0 kWh/dia (uso médio de 8 horas diárias).
- **Micro-ondas**: 0,8 kWh/dia (uso estimado de 20 minutos por dia).
- **Lâmpadas**: 0,6 kWh/dia (cinco lâmpadas de LED usadas por 4 horas diárias).
- **TV**: 0,3 kWh/dia (uso médio de 3 horas diárias).

Os dados no código são baseados em valores aproximados, mas realistas, extraídos de fontes confiáveis como:

- ANEEL - Agência Nacional de Energia Elétrica (www.aneel.gov.br)
- Energy Star e U.S. Department of Energy (www.energy.gov)
- Consumer Reports e outras fontes de eficiência energética

---

## **🌍 Benefícios e impactos**

O EcoHome contribui significativamente para a sustentabilidade ambiental ao reduzir o consumo de energia e, consequentemente, as emissões de gases de efeito estufa. Ele incentiva o uso responsável da eletricidade e promove a adoção de hábitos mais sustentáveis.
A solução fomenta a conscientização da população sobre o impacto do consumo energético, melhorando a educação em sustentabilidade. Isso contribui para a criação de comunidades mais engajadas em práticas responsáveis e incentiva o 
compartilhamento de conhecimento entre os moradores. O projeto ajuda os usuários a identificar padrões de alto consumo, reduzindo os custos mensais de energia elétrica. A médio e longo prazo, o uso de ferramentas como essa pode também impulsionar a busca por dispositivos mais eficientes energeticamente.

---

## **📈 Relevância e acessibilidade**

Nosso projeto se destaca como uma solução alinhada aos desafios globais relacionados ao consumo sustentável de energia, atendendo tanto a residências quanto a potenciais aplicações em negócios e instituições.A integração de dashboards em tempo real, 
alertas automáticos e recomendações baseadas em dados traz um diferencial ao projeto, posicionando-o como uma ferramenta moderna e eficiente para economia de energia. O uso de componentes acessíveis, como a ESP32 e a plataforma gratuita Thinger.io,
torna o EcoHome viável para estudantes, entusiastas de tecnologia e desenvolvedores com recursos limitados. A interface simples e intuitiva foi projetada para usuários com diferentes níveis de familiaridade tecnológica :)

---

## **🛠️ Configuração e replicação**

### **Pré-requisitos**
1. Placa ESP32 configurada com o Arduino IDE
2. Conexão wi-fi estável
3. Conta na plataforma open-source [Thinger.io](https://thinger.io/)

### **Passo a passo**
1. Clone este repositório:
   ```bash
   git clone https://github.com/seu-usuario/ecohome.git´
2. Acesse a plataforma e crie uma conta ou faça login 
3. Na aba "device", clique em "add device" e configure dessa maneira:
   ![image](https://github.com/user-attachments/assets/be4a9c61-ce58-483c-a0ea-a93c64728ab5)
   ![image](https://github.com/user-attachments/assets/8ab89569-2dca-46a2-b4ed-d24b2d973bef)
4. Na aba "dashboard", vá em "add dashboard" e configure dessa maneira:
   ![image](https://github.com/user-attachments/assets/8d21c512-7ca4-48ce-8da1-ae94a6fd3b18)
5. Conecte o microcontrolador via USB em uma das portas do seu computador
6. Abra o arduino IDE com o código clonado desde repositório
7. Substitua as credenciais da rede wifi por alguma rede que você tenha acesso
8. Subistitua as credenciais do dispositivo 
9. Configure os widgets com as especificações mencionadas acima (os resources devem ser selecionados conforme os parâmetros definidos anteriormente no código), exemplo:
    ![image](https://github.com/user-attachments/assets/dd90518f-9873-42e2-9332-9b5e3ae79028)
    ![image](https://github.com/user-attachments/assets/d4198c1e-e13b-4e21-8bc6-9b0bb9aaf73f)
10. Execute o código no ambiente de desenvolvimento e verifique se seu dispositivo está online :)
    ![image](https://github.com/user-attachments/assets/fd04102d-8faf-431b-8cb3-4f05adde6d18)
