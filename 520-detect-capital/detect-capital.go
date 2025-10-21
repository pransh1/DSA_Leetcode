import "strings"
func detectCapitalUse(word string) bool {
    allUpper := true
    allLower := true

    runes := []rune(word)

    for _, ch := range runes {
        if (string(ch)) != strings.ToLower(string(ch)) {
            allLower = false
        }
        if (string(ch)) != strings.ToUpper(string(ch)) {
            allUpper = false
        }
    }

    if allUpper {
        return true
    }

    if allLower {
        return true
    }

    firstUpper := string(runes[0]) == strings.ToUpper(string(runes[0]))
    restLower := true

    for i := 1; i < len(runes); i++ {
        if string(runes[i]) != strings.ToLower(string(runes[i])) {
            restLower = false
            break
        }
    }

    if firstUpper && restLower {
        return true
    }
    return false
}