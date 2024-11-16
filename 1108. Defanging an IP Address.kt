fun defangIPaddr(address: String): String {
        return address.replace(".", "[.]")
    }
