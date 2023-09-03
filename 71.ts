function simplifyPath(path: string): string {
  const splitted = path.split("/");
  const simplified: string[] = [];
  for (const part of splitted) {
    switch (part) {
      case "":
      case ".":
        break;
      case "..":
        simplified.pop();
        break;
      default:
        simplified.push(part);
        break;
    }
  }

  return "/" + simplified.join("/");
}
