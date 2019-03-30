#Importing Biblio
import nltk

#Function to include words in file
def include_words(tagged):
    for x in range(0, len(tagged)):
        if any(
                [tagged[x][1] == "FW", tagged[x][1] == "IN", tagged[x][1] == "JJ",
                 tagged[x][1] == "JJS", tagged[x][1] == "JJR", tagged[x][1] == "NN",
                 tagged[x][1] == "NNP", tagged[x][1] == "NNPS", tagged[x][1] == "NNS",
                 tagged[x][1] == "RB", tagged[x][1] == "RP", tagged[x][1] == "UH",
                 tagged[x][1] == "VB", tagged[x][1] == "VBD", tagged[x][1] == "VBG",
                 tagged[x][1] == "VBN", tagged[x][1] == "VBP", tagged[x][1] == "VBZ"]
        ):
            f.write(str(tagged[x][0]) + '\n')
    return

#Running two times
for y in range(0, 2):
    #Reading a phrase
    phrase= raw_input('Type a phrase: ')
    phrase = nltk.word_tokenize(phrase)
    phrase = nltk.pos_tag(phrase)
    #Opening and saving on file
    f = open(("TEXT_" + str(y) + ".txt"), "w+")
    include_words(phrase)
    #Closing
    f.close()
exit()
