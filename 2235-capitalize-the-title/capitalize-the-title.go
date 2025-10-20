import "strings"

func capitalizeTitle(title string) string {
    words := strings.Fields(strings.ToLower(title))

    for i, word := range words {
        if len(word) >= 3 {
            runes := []rune(word)
            runes[0] = []rune(strings.ToUpper(string(runes[0])))[0]
            words[i] = string(runes)
        } 
    }
    return strings.Join(words, " ")
}