'''
Leandro Madeira
rgm: 45280
'''

class Status:
    def __init__(self, name, PossibleStatusList, alphabetList, beggining, ending):
        self.name = name
        self.PossibleStatusList = PossibleStatusList
        self.alphabetList = alphabetList
        self.beggining = beggining
        self.ending = ending


def creating_table(automaton):

    table = {
    }
    for i in range(len(automaton)):
        for j in range(len(automaton)):
            if j != i and j > i:
                if automaton[i].ending != automaton[j].ending:
                    aux = automaton[i].name + ',' + automaton[j].name
                    print(aux)
                    table[aux] = 'x'
                else:
                    aux = automaton[i].name + ',' + automaton[j].name
                    print(aux)
                    table[aux] = '0'
            else:
                continue

    for i in table:
        if table[i] == '0':
            aux = i.split(',')
            indice = 0

            for j in automaton:
                if (j.name == aux[0]):
                    aux1 = j
                if (j.name == aux[1]):
                    aux2 = j

            for k in range(len(aux1.alphabetList)):
                auxEst = aux1.PossibleStatusList[k] + ',' + aux2.PossibleStatusList[k]
                auxEstInv = aux2.PossibleStatusList[k] + ',' + aux1.PossibleStatusList[k]
                if (auxEst not in table and auxEstInv not in table):
                    continue
                elif (auxEst in table and auxEstInv not in table):
                    if (table[auxEst] == 'x'):
                        table[i] = 'x'
                    else:
                        for l in automaton:
                            if (l.name == aux1.PossibleStatusList[k]):
                                auxiliar1 = l
                            elif (l.name == aux2.PossibleStatusList[k]):
                                auxiliar2 = l
                        if ((auxiliar1.ending == False and auxiliar2.ending == True) or (
                                auxiliar2.ending == False and auxiliar1.ending == True)):
                            table[i] = 'x'
                        else:
                            table[auxEst] = i
                else:
                    if (table[auxEstInv] == 'x'):
                        table[i] = 'x'
                    else:
                        for l in automaton:
                            if (l.nome == aux1.PossibleStatusList[k]):
                                auxiliar1 = l
                            elif (l.nome == aux2.PossibleStatusList[k]):
                                auxiliar2 = l
                        if ((auxiliar1.ending == False and auxiliar2.final == True) or (
                                auxiliar2.ending == False and auxiliar1.final == True)):
                            table[i] = 'x'
                        else:
                            table[auxEstInv] = i
        elif (table[i] == 'x'):
            continue
        else:
            guardar = table[i]
            aux = i.split(',')
            for j in automaton:
                if (j.name == aux[0]):
                    aux1 = j
                if (j.name == aux[1]):
                    aux2 = j

            # Verify possible status
            for k in range(len(aux1.alphabetList)):
                auxEst = aux1.PossibleStatusList[k] + ',' + aux2.PossibleStatusList[k]
                auxEstInv = aux2.PossibleStatusList[k] + ',' + aux1.PossibleStatusList[k]
                if (auxEst not in table and auxEstInv not in table):
                    continue
                else:
                    for l in automaton:
                        if (l.name == aux1.PossibleStatusList[k]):
                            auxiliar1 = l
                        elif (l.name == aux2.PossibleStatusList[k]):
                            auxiliar2 = l
                    if ((auxiliar1.ending == False and auxiliar2.ending == True) or (
                            auxiliar2.ending == False and auxiliar1.ending == True)):
                        table[guardar] = 'x'
                        table[i] = 'x'
                    else:
                        table[guardar] = '0'
                        table[i] = '0'
    print(table)


def aceite_palavra(automaton, word):
    aceita = True
    estadoAtual = automaton[0]
    indice = 0

    while (True):
        for i in range(len(estadoAtual.alphabetList)):
            if (estadoAtual.alphabetList[i] == word[indice]):
                for j in automaton:
                    if (estadoAtual.PossibleStatusList[i] == j.name):
                        estadoAtual = j
                        break
                break
        indice += 1
        if (indice == len(word)):
            if (estadoAtual.ending == False):
                aceita = False
            break

    if (aceita):
        return 'A palavra foi aceita.'
    else:
        return 'A palavra nao foi aceita.'

def main():
    while (True):
        q0 = Status('q0', ['q1', 'q3'], ['a', 'b'], True, False)
        q1 = Status('q1', ['q3', 'q2'], ['a', 'b'], False, False)
        q2 = Status('q2', ['q2', 'q2'], ['a', 'b'], False, True)
        q3 = Status('q3', ['q3', 'q3'], ['a', 'b'], False, False)
        automaton = [q0, q1, q2, q3]

        palavra = input("Insira a palavra ou -1 para encerrar: ")

        if (palavra == '-1'):

            break
        palavra_aceita = aceite_palavra(automaton, palavra)
        print(palavra_aceita)

        creating_table(automaton)

main()