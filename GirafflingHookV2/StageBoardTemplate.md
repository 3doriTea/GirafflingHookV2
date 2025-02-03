# StageBoardTemplate

Unityで使えるお手軽コンバートするためのやーつ

```cs
using UnityEngine;
using UnityEditor;
using System.Text;

public class GHStageConverter : MonoBehaviour
{
	public string giraffePointName;
	public Transform stageRootTransform;
}

#if UNITY_EDITOR
[CustomEditor(typeof(GHStageConverter))]
public class GHStageEditor : Editor
{
	enum StagePartsType
	{
		Wall,
		GiraffePoint,
	}

	private static string giraffePointTag = "";

	public override void OnInspectorGUI()
	{
		base.OnInspectorGUI();

		var t = target as GHStageConverter;

		if (GUILayout.Button("Convert"))
		{
			var outCode = new StringBuilder();
			ConvertChilds(t.stageRootTransform, ref outCode);
			Debug.Log(outCode);
		}

		static void ConvertChilds(Transform parent, ref StringBuilder builder)
		{
			foreach (Transform child in parent)
			{
				var type = child.CompareTag(giraffePointTag)
					? StagePartsType.GiraffePoint
					: StagePartsType.Wall;
				builder.AppendLine(ConvertCpp(child, type));
				ConvertChilds(child, ref builder);
			}
		}
	}

	static string ConvertCpp(Transform transform, StagePartsType type)
	{
		switch (type)
		{
			case StagePartsType.GiraffePoint:
				return string.Join("\n", new string[]
				{
					$"\tInstantiate<StageBoard>(",
					$"\t\t\"{transform.name}\",",
					$"\t\tVector3{{ {transform.position.x * 100f:f4}f, {transform.position.y * 100f:f4}f, {transform.position.z * 100f:f4}f }},",
					$"\t\tVector3{{ {transform.localScale.x * 100f:f4}f, {transform.localScale.y * 100f:f4}f, {transform.localScale.z * 100f:f4}f }});",
				});
			case StagePartsType.Wall:
			default:
				return string.Join("\n", new string[]
				{
					$"\tInstantiate<StageBoard>(",
					$"\t\t\"{transform.name}\",",
					$"\t\tVector3{{ {transform.position.x * 100f:f4}f, {transform.position.y * 100f:f4}f, {transform.position.z * 100f:f4}f }},",
					$"\t\tVector3{{ {transform.localScale.x * 100f:f4}f, {transform.localScale.y * 100f:f4}f, {transform.localScale.z * 100f:f4}f }});",
				});
		}
	}
}
#endif

```
