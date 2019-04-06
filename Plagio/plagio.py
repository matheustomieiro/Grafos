import nltk # Importing library


def include_words(tagged, f):  # Function to include words in file
        for x in range(0, len(tagged)):
                if any(
                        # Testing if the word belongs to the desired word classes
                        # For all word classes in NLTK, on python: nltk.help.upenn_tagset()
                        [tagged[x][1] == "FW", tagged[x][1] == "IN", tagged[x][1] == "JJ",
                        tagged[x][1] == "JJS", tagged[x][1] == "JJR", tagged[x][1] == "NN",
                        tagged[x][1] == "NNP", tagged[x][1] == "NNPS", tagged[x][1] == "NNS",
                        tagged[x][1] == "RB", tagged[x][1] == "RP", tagged[x][1] == "UH",
                        tagged[x][1] == "VB", tagged[x][1] == "VBD", tagged[x][1] == "VBG",
                        tagged[x][1] == "VBN", tagged[x][1] == "VBP", tagged[x][1] == "VBZ"]
                ):
                        f.write((str(tagged[x][0])).lower() + ' ' + str(tagged[x][1].lower()) + '\0' + '\n')
        return


def main():
        for y in range(0, 2):  # Running two times
                phrase = raw_input()  # Reading a phrase
                phrase = nltk.word_tokenize(phrase)
                phrase = nltk.pos_tag(phrase)
                file = open(("TEXT_" + str(y) + ".txt"), "w+")  # Opening and saving on file
                include_words(phrase, file)
                file.close()   # Closing
        return(0)


if __name__ == "__main__":
        main()