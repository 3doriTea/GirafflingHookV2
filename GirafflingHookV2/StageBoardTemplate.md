# StageBoardTemplate

�X�e�[�W�{�[�h�̃C���X�^���X�R�[�h��Unity���玝���Ă���ꍇ�̃R�[�h�t�H�[�}�b�g

```cs
void ConvertCpp(Transform transform)

var stageCode = string.Join("\n", [
    "    Instantiate<StageBoard>(",
    "        \"{transform.name}\",",
    "        Vector3{{ {transform.position.x}f, {transform.position.y}f, {transform.position.z}f }},",
    "        Vector3{{ {transform.scale.x}f, {transform.scale.y}f, {transform.scale.z}f }});",
    ]);

Console.WriteLine(stageCode);
```
