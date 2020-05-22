      #include "Keypad.h" // inclusion de la librairie pour clavier matriciel 
      //--- Constantes utilisées avec le clavier 4x4 
      const byte LIGNES = 4;            // 4 lignes 
      const byte COLONNES = 4;       // 4 colonnes 
      
      // déclaration des broches --- 
      const int L1=5; 
      const int L2=6; 
      const int L3=7; 
      const int L4=8; 
      
      const int R1=9; 
      const int R2=2; 
      const int R3=3; 
      const int R4=4; 
      
      const int LED=10; //D8

      int cpt = 0;

      int prog_maitre = 0;
      int pin0 = 0;
      int pin1 = 0;
      int pin2 = 0;
      int pin3 = 0;

      int norm = 0;
      int code0 = 0;
      int code1 = 0;
      int code2 = 0;
      int code3 = 0;
      
      char touches[LIGNES][COLONNES] = { 
            {'1','2','3','A'}, 
            {'4','5','6','B'}, 
            {'7','8','9','C'}, 
            {'*','0','#','D'} 
      }; 
      
      byte BrochesLignes[LIGNES] = {L1, L2, L3, L4}; 
      byte BrochesColonnes[COLONNES] = {R1, R2, R3, R4}; 
      
      char touche; 
      
      // création d'un objet keypad = initialisation clavier 
      Keypad clavier = Keypad( makeKeymap(touches), BrochesLignes, BrochesColonnes, LIGNES, COLONNES ); 
      // les broches de lignes sont configurées en ENTREE avec pullup interne activé 
      // les broches de colonnes sont configurées en SORTIE 
      
      void setup()             { 
          Serial.begin(9600); 
          delay(10); // pause rapide pour laisser temps initialisation 
      
            Serial.println("init OK") ; // affiche la chaîne texte - message de test 
            delay(2000); // pause de 2 secondes 

            pinMode(LED, OUTPUT);
            digitalWrite(LED, HIGH);

            Serial.println("Sommaire : \n");
            Serial.println("A : Pour valider après avoir entré le code \n");
            Serial.println("B : Pour modifier le code maître \n");
            Serial.println("C : Pour entrer le code et ouvrir la porte \n");
            Serial.println("D : Pour annuler et recommencer l'entrée du code \n");
      } // fin de la fonction setup() 
      
      void loop() { 
            touche = clavier.getKey(); // lecture de la touche appuyée 
        
            if (touche != NO_KEY){ // si une touche a été frappée -- gestion de la touche appuyée 
                  Serial.print(touche); 
                  Serial.print(" "); 
                  delay(300); // pause entre 2 appuis 
                  cpt++;

                 

                  if(touche == 'B')
                  {
                    prog_maitre = 1;
                    Serial.print("Prog code maître\n");
                  }
                  
                  else if(prog_maitre == 1)
                  {
                    Serial.print("Save pin0\n");
                    pin0 = touche-'0';
                    prog_maitre++;
                  }

                  else if(prog_maitre == 2)
                  {
                    Serial.print("Save pin1\n");
                    pin1 = touche-'0';
                    prog_maitre++;
                  }

                  else if(prog_maitre == 3)
                  {
                    Serial.print("Save pin2\n");
                    pin2 = touche-'0';
                    prog_maitre++;
                  }
                  
                  else if(prog_maitre == 4)
                  {
                    Serial.print("Save pin3\n");
                    pin3 = touche-'0';
                    Serial.print("Fin Prog code maître\n");
                    Serial.print("Voici le code :\n");
                    Serial.print(pin0);
                    Serial.print(pin1);
                    Serial.print(pin2);
                    Serial.print(pin3);
                    Serial.print("\n");

                  
                    digitalWrite(LED, LOW);
                    delay(50);
                    digitalWrite(LED, HIGH);
                    delay(50);
                    digitalWrite(LED, LOW);
                    delay(50);
                    digitalWrite(LED, HIGH);
                    delay(50);
                    
                    
                    prog_maitre=0;
                  }
                

                  else if(prog_maitre == 0)
                  {
                    if(touche == 'A')
                    {
                      if((code0 == pin0) && (code1 == pin1) && (code2 == pin2) && (code3 == pin3))
                      {
                        Serial.print("OPEN !\n");
                        code0 = 0;
                        code1 = 0;
                        code2 = 0;
                        code3 = 0;

                        prog_maitre = 0;
                        digitalWrite(LED, LOW);
                        delay(3000);
                        digitalWrite(LED, HIGH);
                      }
                      else
                      {
                        Serial.print("ERROR !\n");
                        for(int i=200; i>=50; i=i-25)
                        {
                          digitalWrite(LED, LOW);
                          delay(i);
                          digitalWrite(LED, HIGH);
                          delay(i);
                        }
                        norm = 1;
                      }
                    }

                    else if(touche == 'C')
                    {
                      Serial.println("Entrez le code :\n");
                      norm = 1;
                      prog_maitre = 0;
                    }

                    else if(touche == 'D')
                    {
                      norm = 1;
                      Serial.print("Recommencement\n");
                    }
                    
                    else if(norm == 1)
                    {
                      Serial.print("code 0!\n");
                      code0 = touche-'0';
                      norm++;
                    }

                    else if(norm == 2)
                    {
                      Serial.print("code 1!\n");
                      code1 = touche-'0';
                      norm++;
                    }
                    
                    else if(norm == 3)
                    {
                      Serial.print("code 2!\n");
                      code2 = touche-'0';
                      norm++;
                    }
                    
                    else if(norm == 4)
                    {
                      Serial.print("code 3!\n");
                      code3 = touche-'0';
                      norm = 0;
                    }
                  }
            }             // fin gestion de la touche appuyée 
      } 
